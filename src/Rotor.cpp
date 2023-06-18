#include "Rotor.h"
#include <iostream>
#include "functions.h"

using namespace std;

Rotor::Rotor(char* w, char initialOffset): wiring(w), offset(charToInt(initialOffset) - 1) {} ;


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
