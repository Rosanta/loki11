#include "functor.h"

#include "gtest/gtest.h"
#include "glog/logging.h"

namespace loki11 {

TEST(testClassFunc, functor) {
    struct foo {
        bool operator() (int a, int b) {
            return false;
        }
    };

    foo obj;
    Functor<bool, int, int> a(obj);
    ASSERT_FALSE(a(1, 2));
}

TEST(testLambda, functor) {
    auto a = [] (int a, char b, bool c) -> double {
        return 3.12;
    };

    Functor<double, int, char, bool> f(a);
    ASSERT_EQ(f(1,2,false), 3.12);
}

}   // namespace loki11
