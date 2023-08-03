#include <gtest/gtest.h>
#include "../src/functions.h"

TEST(functions_test, charToInt) {
    EXPECT_EQ(charToInt('A'), 0);
    EXPECT_EQ(charToInt('B'), 1);
    EXPECT_EQ(charToInt('Z'), 25);
}

TEST(functions_test, intToChar) {
    EXPECT_EQ(intToChar(0), 'A');
    EXPECT_EQ(intToChar(1), 'B');
    EXPECT_EQ(intToChar(25), 'Z');
}
