#include <gtest/gtest.h>
int Foo(int a, int b) {
    if (0 == a || 0 == b)
        throw "don't do that";
    int c = a % b;
    if (0 == c) {
        return b;
    }
    return Foo(b, c);
}

TEST(FooTest, HandleNoneZeroInput) {
    EXPECT_EQ(2, Foo(4, 10));
    EXPECT_EQ(6, Foo(30, 18));
}
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// g++ -std=c++14 tmp.cpp -lgtest -lpthread