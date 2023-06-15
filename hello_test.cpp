#include <gtest/gtest.h>
#include "functions.h"

TEST(HelloTest, BasicAssertions) {
    EXPECT_EQ(charToInt('A'), 1);
    EXPECT_EQ(charToInt('B'), 2);
    EXPECT_EQ(charToInt('Z'), 26);
}
