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

    loki11::CompileError<true>();
}

