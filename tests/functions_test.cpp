#include <gtest/gtest.h>
#include "../src/functions.h"

TEST(functions_test, charToInt) {
    EXPECT_EQ(charToInt('A'), 1);
    EXPECT_EQ(charToInt('B'), 2);
    EXPECT_EQ(charToInt('Z'), 26);
}
