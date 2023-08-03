#include <gtest/gtest.h>
#include "../src/Rotor.h"

TEST(Rotor_test, encode)
{
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

TEST(Rotor_test, rotate)
{
    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    rotor_I.rotate();

    EXPECT_EQ(rotor_I.encode('A'), 'J');
    EXPECT_EQ(rotor_I.encode('B'), 'L');
    EXPECT_EQ(rotor_I.encode('C'), 'E');
}

TEST(Rotor_test, rotate_multiple)
{
    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    for (int i = 0; i <= 26; i++) { 
        rotor_I.rotate();
    }

    EXPECT_EQ(rotor_I.encode('A'), 'J');
    EXPECT_EQ(rotor_I.encode('B'), 'L');
    EXPECT_EQ(rotor_I.encode('C'), 'E');
}

TEST(Rotor_test, encodeBack)
{
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

TEST(Rotor_test, encodeBack_afterRotation)
{
    //               ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Rotor rotor_III("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A');
    rotor_III.rotate();

    EXPECT_EQ(rotor_III.encodeBack('E'), 'B');
    EXPECT_EQ(rotor_III.encodeBack('C'), 'A');
    EXPECT_EQ(rotor_III.encodeBack('V'), 'Q');
    EXPECT_EQ(rotor_III.encodeBack('M'), 'M');
    EXPECT_EQ(rotor_III.encodeBack('B'), 'F');
    EXPECT_EQ(rotor_III.encodeBack('K'), 'E');
    EXPECT_EQ(rotor_III.encodeBack('P'), 'X');
    EXPECT_EQ(rotor_III.encodeBack('S'), 'I');
    EXPECT_EQ(rotor_III.encodeBack('Q'), 'H');
    EXPECT_EQ(rotor_III.encodeBack('Z'), 'S');
    EXPECT_EQ(rotor_III.encodeBack('R'), 'W');
    EXPECT_EQ(rotor_III.encodeBack('H'), 'P');
    EXPECT_EQ(rotor_III.encodeBack('I'), 'D');
    EXPECT_EQ(rotor_III.encodeBack('N'), 'Y');
    EXPECT_EQ(rotor_III.encodeBack('J'), 'T');
    EXPECT_EQ(rotor_III.encodeBack('Y'), 'L');
    EXPECT_EQ(rotor_III.encodeBack('G'), 'C');
    EXPECT_EQ(rotor_III.encodeBack('T'), 'V');
    EXPECT_EQ(rotor_III.encodeBack('W'), 'J');
    EXPECT_EQ(rotor_III.encodeBack('D'), 'O');
    EXPECT_EQ(rotor_III.encodeBack('A'), 'Z');
    EXPECT_EQ(rotor_III.encodeBack('F'), 'R');
    EXPECT_EQ(rotor_III.encodeBack('U'), 'K');
    EXPECT_EQ(rotor_III.encodeBack('O'), 'G');
    EXPECT_EQ(rotor_III.encodeBack('X'), 'N');
    EXPECT_EQ(rotor_III.encodeBack('L'), 'U');
}