#include "typelist.h"

#include <gtest/gtest.h>

using namespace loki11::typelist;

struct dummy {
  public:
    dummy() = delete;
    dummy(int) {};
};

TEST(typelist, simpletest) {
    auto list = TypeList<int, char, double>();

    ASSERT_EQ(Length<decltype(list)>::value, 3);

    TypeAt<TypeList<int, char, double, dummy>, 3>::type a(3);

    TypeAtNonStrict<TypeList<int, char, double>, 10, dummy>::type b(2);

    int idx = IndexOf<TypeList<int, char, double>, short>::value;
    ASSERT_EQ(idx, -1);
    idx  = IndexOf<TypeList<int, char, double>, char>::value;
    ASSERT_EQ(idx, 1);

    int len = Length<Append<TypeList<char, long, long>, short>::type>::value; 
    ASSERT_EQ(len, 4);
}


TEST(typelist, testpophead) {
    auto list = TypeList<int, char, double, dummy>();

    ASSERT_EQ(Length<decltype(list)>::value, 4);

    PopHead<decltype(list), 2>::type result;
    ASSERT_EQ(Length<decltype(result)>::value, 2);

    TypeAt<decltype(result), 1>::type pp(321);
}