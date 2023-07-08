#include <gtest/gtest.h>
#include "../src/Plugboard.h"

TEST(Plugboard_encode_test, should_do_nothing_when_no_pairs) {
    Plugboard plugboard;

    EXPECT_EQ(plugboard.encode('A'), 'A');
    EXPECT_EQ(plugboard.encode('B'), 'B');
    EXPECT_EQ(plugboard.encode('C'), 'C');
    EXPECT_EQ(plugboard.encode('Z'), 'Z');
}

TEST(Plugboard_encode_test, should_encode_pairs) {
    vector<pair<char, char>> pairs = {make_pair('A', 'B'), make_pair('C', 'D')};
    Plugboard plugboard(pairs);

    EXPECT_EQ(plugboard.encode('A'), 'B');
    EXPECT_EQ(plugboard.encode('B'), 'A');
    EXPECT_EQ(plugboard.encode('C'), 'D');
    EXPECT_EQ(plugboard.encode('D'), 'C');
    EXPECT_EQ(plugboard.encode('E'), 'E');
    EXPECT_EQ(plugboard.encode('Z'), 'Z');
}