#include <gtest/gtest.h>
#include <string>
#include "../src/Enigma.h"

using namespace std;

TEST(Enigma_test, should_encode_simple_string_with_rotation)
{
    auto rotorI = make_unique<Rotor>("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    auto rotorII = make_unique<Rotor>("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'A');
    auto rotorIII = make_unique<Rotor>("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A');

    vector<pair<char, char>> pairs = {};
    auto plugboard = make_unique<Plugboard>(pairs);

    auto ukwB = make_unique<Reflector>("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    Enigma enigma(rotorI, rotorII, rotorIII, plugboard, ukwB);

    EXPECT_EQ(enigma.encode("AAAAAAAAAAAAAAAAAAAAAAA"), "BDZGOWCXLTKSBTMCDLPBMUQ");
}

TEST(Enigma_test, should_encode_string_with_rotation)
{
    auto rotorI = make_unique<Rotor>("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    auto rotorII = make_unique<Rotor>("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'B');
    auto rotorIII = make_unique<Rotor>("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'C');

    vector<pair<char, char>> pairs = {};
    auto plugboard = make_unique<Plugboard>(pairs);

    auto ukwB = make_unique<Reflector>("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    Enigma enigma(rotorI, rotorII, rotorIII, plugboard, ukwB);

    EXPECT_EQ(enigma.encode("CONVOYDESTROYED"), "AEFMLZGZEWFULUW");
}

TEST(Enigma_test, should_encode_string_with_plugboard)
{
    auto rotorI = make_unique<Rotor>("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    auto rotorII = make_unique<Rotor>("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'B');
    auto rotorIII = make_unique<Rotor>("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'C');

    vector<pair<char, char>> pairs = {make_pair('A', 'B')};
    auto plugboard = make_unique<Plugboard>(pairs);

    auto ukwB = make_unique<Reflector>("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    Enigma enigma(rotorI, rotorII, rotorIII, plugboard, ukwB);

    EXPECT_EQ(enigma.encode("CONVOYDESTROYED"), "BEFMLZGZEWFULUW");
}