#include <iostream>
#include "src/Rotor.h"
#include "src/Plugboard.h"
#include "src/Enigma.h"
#include "src/functions.h"

using namespace std;

int main()
{
    cout << "Enigma Machine" << endl;

    auto rotorI = make_unique<Rotor>("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    auto rotorII = make_unique<Rotor>("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'A');
    auto rotorIII = make_unique<Rotor>("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A');

    vector<pair<char, char>> pairs = {};
    auto plugboard = make_unique<Plugboard>(pairs);

    Enigma enigma(rotorI, rotorII, rotorIII, plugboard);

    char toEncode = 'A';
    char encoded = enigma.encode('A');

    cout << "Letter '" << toEncode << "' encoded to '" << encoded << "'." << endl;

    return 0;
}
