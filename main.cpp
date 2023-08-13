#include <iostream>
#include "src/Rotor.h"
#include "src/Plugboard.h"
#include "src/Enigma.h"
#include "src/functions.h"

using namespace std;

void getUserInput(string &input)
{
    cout << "Type text to encode (\"exit\" will close the program) " << endl;
    cin >> input;
}

bool userInpupIsValid(const string &input)
{
    for (char l : input)
    {
        if (charToInt(l) < 0 || charToInt(l) > 25)
        {
            cout << "[ERROR] Input contains incorrect not encodable character: '" << l << "'." << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    auto rotorI = make_unique<Rotor>("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');
    auto rotorII = make_unique<Rotor>("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'A');
    auto rotorIII = make_unique<Rotor>("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'A');
    auto pairs = {make_pair('A', 'B')};
    auto plugboard = make_unique<Plugboard>(pairs);
    auto ukwB = make_unique<Reflector>("YRUHQSLDPXNGOKMIEBFZCWVJAT");
    Enigma enigma(rotorI, rotorII, rotorIII, plugboard, ukwB);

    cout << "Enigma Machine" << endl;

    string input;
    getUserInput(input);

    while (input != "exit" && userInpupIsValid(input))
    {
        string encoded = enigma.encode(input);
        cout << "Text to encode: " << input << endl;
        cout << "Encoded text: " << encoded << endl;
        getUserInput(input);
    };

    return 0;
}
