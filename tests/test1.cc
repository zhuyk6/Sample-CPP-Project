#include "foo.h"
#include <gtest/gtest.h>
#include <random>

TEST(SampleTest, BasicAssertions) {
    EXPECT_EQ(1, 1);
}

TEST(FooTest, Add) {
    Foo foo;
    EXPECT_EQ(foo.add(1, 2), 3);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-100, 100);

    // some random tests
    for (int i = 0; i < 100; ++i) {
        int x = dist(gen);
        int y = dist(gen);
        EXPECT_EQ(foo.add(x, y), x + y);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
