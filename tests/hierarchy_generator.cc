#include "hierarchy_generator.h"

#include "gtest/gtest.h"

#include "utility.h"

using namespace loki11::hierarchy_generator;

template <typename T> 
struct Holder {
    T value_;
};

TEST(simpletest, hierarchy_generator) {
    ASSERT_TRUE(true);

    auto obj = GenScatterHierarchy<loki11::typelist::TypeList<int, char, int, int>, Holder>();

    Field<char>(obj).value_ = 0;

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

