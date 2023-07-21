#include <gtest/gtest.h>
#include "../src/Reflector.h"

TEST(Reflector_test, encode) {
    //         ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Reflector ukwB("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    EXPECT_EQ(ukwB.encode('A'), 'Y');
    EXPECT_EQ(ukwB.encode('B'), 'R');
    EXPECT_EQ(ukwB.encode('C'), 'U');
    EXPECT_EQ(ukwB.encode('D'), 'H');
    EXPECT_EQ(ukwB.encode('E'), 'Q');
    EXPECT_EQ(ukwB.encode('F'), 'S');
    EXPECT_EQ(ukwB.encode('G'), 'L');
    EXPECT_EQ(ukwB.encode('H'), 'D');
    EXPECT_EQ(ukwB.encode('I'), 'P');
    EXPECT_EQ(ukwB.encode('J'), 'X');
    EXPECT_EQ(ukwB.encode('K'), 'N');
    EXPECT_EQ(ukwB.encode('L'), 'G');
    EXPECT_EQ(ukwB.encode('M'), 'O');
    EXPECT_EQ(ukwB.encode('N'), 'K');
    EXPECT_EQ(ukwB.encode('O'), 'M');
    EXPECT_EQ(ukwB.encode('P'), 'I');
    EXPECT_EQ(ukwB.encode('Q'), 'E');
    EXPECT_EQ(ukwB.encode('R'), 'B');
    EXPECT_EQ(ukwB.encode('S'), 'F');
    EXPECT_EQ(ukwB.encode('T'), 'Z');
    EXPECT_EQ(ukwB.encode('U'), 'C');
    EXPECT_EQ(ukwB.encode('V'), 'W');
    EXPECT_EQ(ukwB.encode('W'), 'V');
    EXPECT_EQ(ukwB.encode('X'), 'J');
    EXPECT_EQ(ukwB.encode('Y'), 'A');
    EXPECT_EQ(ukwB.encode('Z'), 'T');
}