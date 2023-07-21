#include "WiringRing.h"
#include <iostream>
#include "functions.h"

using namespace std;

WiringRing::WiringRing(const char *w) : wiring(w){};

char WiringRing::encode(char letter, int offset)
{
    char wiringToLetter = this->wiring[(charToInt(letter) - 1 + offset) % 26];
    int wiringShift = charToInt(wiringToLetter) - (charToInt(letter) + offset % 26);
    int encodedLetterIndex = charToInt(letter) + wiringShift;
    return intToChar(encodedLetterIndex);
}
