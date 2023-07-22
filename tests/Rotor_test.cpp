#include <gtest/gtest.h>
#include "../src/Rotor.h"

TEST(Rotor_test, encode) {
    //             ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');

    EXPECT_EQ(rotor_I.encode('A'), 'E');
    EXPECT_EQ(rotor_I.encode('B'), 'K');
    EXPECT_EQ(rotor_I.encode('C'), 'M');
    EXPECT_EQ(rotor_I.encode('D'), 'F');
    EXPECT_EQ(rotor_I.encode('E'), 'L');
    EXPECT_EQ(rotor_I.encode('F'), 'G');
    EXPECT_EQ(rotor_I.encode('G'), 'D');
    EXPECT_EQ(rotor_I.encode('H'), 'Q');
    EXPECT_EQ(rotor_I.encode('I'), 'V');
    EXPECT_EQ(rotor_I.encode('J'), 'Z');
    EXPECT_EQ(rotor_I.encode('K'), 'N');
    EXPECT_EQ(rotor_I.encode('L'), 'T');
    EXPECT_EQ(rotor_I.encode('M'), 'O');
    EXPECT_EQ(rotor_I.encode('N'), 'W');
    EXPECT_EQ(rotor_I.encode('O'), 'Y');
    EXPECT_EQ(rotor_I.encode('P'), 'H');
    EXPECT_EQ(rotor_I.encode('Q'), 'X');
    EXPECT_EQ(rotor_I.encode('R'), 'U');
    EXPECT_EQ(rotor_I.encode('S'), 'S');
    EXPECT_EQ(rotor_I.encode('T'), 'P');
    EXPECT_EQ(rotor_I.encode('U'), 'A');
    EXPECT_EQ(rotor_I.encode('U'), 'A');
    EXPECT_EQ(rotor_I.encode('V'), 'I');
    EXPECT_EQ(rotor_I.encode('X'), 'R');
    EXPECT_EQ(rotor_I.encode('Y'), 'C');
    EXPECT_EQ(rotor_I.encode('Z'), 'J');
}

TEST(Rotor_test, rotate) {
    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    rotor_I.rotate();

    EXPECT_EQ(rotor_I.encode('A'), 'J');
    EXPECT_EQ(rotor_I.encode('B'), 'L');
    EXPECT_EQ(rotor_I.encode('C'), 'E');
}

TEST(Rotor_test, encodeBack) {
    //             ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');

    EXPECT_EQ(rotor_I.encodeBack('E'), 'A');
    EXPECT_EQ(rotor_I.encodeBack('K'), 'B');
    EXPECT_EQ(rotor_I.encodeBack('M'), 'C');
    EXPECT_EQ(rotor_I.encodeBack('F'), 'D');
    EXPECT_EQ(rotor_I.encodeBack('L'), 'E');
    EXPECT_EQ(rotor_I.encodeBack('G'), 'F');
    EXPECT_EQ(rotor_I.encodeBack('D'), 'G');
    EXPECT_EQ(rotor_I.encodeBack('Q'), 'H');
    EXPECT_EQ(rotor_I.encodeBack('V'), 'I');
    EXPECT_EQ(rotor_I.encodeBack('Z'), 'J');
    EXPECT_EQ(rotor_I.encodeBack('N'), 'K');
    EXPECT_EQ(rotor_I.encodeBack('T'), 'L');
    EXPECT_EQ(rotor_I.encodeBack('O'), 'M');
    EXPECT_EQ(rotor_I.encodeBack('W'), 'N');
    EXPECT_EQ(rotor_I.encodeBack('Y'), 'O');
    EXPECT_EQ(rotor_I.encodeBack('H'), 'P');
    EXPECT_EQ(rotor_I.encodeBack('X'), 'Q');
    EXPECT_EQ(rotor_I.encodeBack('U'), 'R');
    EXPECT_EQ(rotor_I.encodeBack('S'), 'S');
    EXPECT_EQ(rotor_I.encodeBack('P'), 'T');
    EXPECT_EQ(rotor_I.encodeBack('A'), 'U');
    EXPECT_EQ(rotor_I.encodeBack('A'), 'U');
    EXPECT_EQ(rotor_I.encodeBack('I'), 'V');
    EXPECT_EQ(rotor_I.encodeBack('R'), 'X');
    EXPECT_EQ(rotor_I.encodeBack('C'), 'Y');
    EXPECT_EQ(rotor_I.encodeBack('J'), 'Z');
}