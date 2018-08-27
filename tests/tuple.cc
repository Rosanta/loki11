#include "tuple.h"

#include <gtest/gtest.h>

#include "typelist.h"

namespace loki11 {

TEST(simpletest, tupletest) {
    Tuple<int, int, int, int> tuple;

    Field<0>(tuple).Get() = 4;
    Field<1>(tuple).Get() = 3;
    Field<2>(tuple).Get() = 2;
    Field<3>(tuple).Get() = 1;
    ASSERT_EQ(Field<0>(tuple).Get(), 4);
    ASSERT_EQ(Field<1>(tuple).Get(), 3);
    ASSERT_EQ(Field<2>(tuple).Get(), 2);
    ASSERT_EQ(Field<3>(tuple).Get(), 1);
}

}   // namespace loki11