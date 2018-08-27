#include "hierarchy_generator.h"

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

}   // namespace loki11

