#include "hierarchy_generator.h"

#include <type_traits>

#include "gtest/gtest.h"

#include "utility.h"


template <typename T>
struct Holder {
    T value_;
};

namespace loki11 {

TEST(testType, hierarchy_generator) {
    ASSERT_TRUE(true);

    auto obj = GenScatterHierarchy<TypeList<int, char, double>, Holder>();

    Field<double>(obj).value_ = 3.321;
    ASSERT_EQ(Field<double>(obj).value_, 3.321);

    ASSERT_TRUE((std::is_same<decltype(Field<double>(obj).value_), double>::value));
    ASSERT_TRUE((std::is_same<decltype(Field<char>(obj).value_), char>::value));
    ASSERT_TRUE((std::is_same<decltype(Field<int>(obj).value_), int>::value));
}

TEST(testIndex, hierarchy_generator) {
    auto obj = GenScatterHierarchy<TypeList<int, int, int, int>, Holder>();

    Field<0>(obj).value_ = 0;
    Field<1>(obj).value_ = 1;
    Field<2>(obj).value_ = 2;
    Field<3>(obj).value_ = 3;

    ASSERT_EQ(Field<0>(obj).value_, 0);
    ASSERT_EQ(Field<1>(obj).value_, 1);
    ASSERT_EQ(Field<2>(obj).value_, 2);
    ASSERT_EQ(Field<3>(obj).value_, 3);

    loki11::CompileError<true>();
}

template <typename T, typename U>
class EventHandler : public U {
  public:
    virtual T onEvent(T data) = 0;
};

class ValueHandler: public
    GenLinearHierarchy<TypeList<int, char, double>, EventHandler>  {
  public:
    virtual int onEvent(int data) override { return 0; }
    virtual char onEvent(char data) override { return 0; }
    virtual double onEvent(double data) override { return 0; }
};

TEST(testLiearHierarchy, hierarchy_generator) {
    ValueHandler vh;

    ASSERT_TRUE((std::is_same<decltype(vh.onEvent(123)), int>::value));
    ASSERT_TRUE((std::is_same<decltype(vh.onEvent('c')), char>::value));
    ASSERT_TRUE((std::is_same<decltype(vh.onEvent(123.321)), double>::value));
}

}   // namespace loki11

