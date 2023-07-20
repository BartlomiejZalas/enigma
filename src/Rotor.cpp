#include "Rotor.h"
#include <iostream>
#include "functions.h"

using namespace std;

Rotor::Rotor(const char *w, char io) : wiring(w), offset(charToInt(io) - 1){};

void Rotor::rotate()
{
    ++this->offset;
}

char Rotor::encode(char letter)
{
    char wiringToLetter = this->wiring[(charToInt(letter) - 1 + this->offset) % 26];
    int wiringShift = charToInt(wiringToLetter) - (charToInt(letter) + this->offset % 26);
    int encodedLetterIndex = charToInt(letter) + wiringShift;
    return intToChar(encodedLetterIndex);
}

int Rotor::getOffset()
{
    return this->offset;
}
