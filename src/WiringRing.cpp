#include <iostream>
#include <algorithm>
#include "WiringRing.h"
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

char WiringRing::encodeBack(char letter, int offset)
{
    return intToChar(this->findIndex(letter) + 1);
}

char WiringRing::findIndex(char letter)
{
    const char *end = wiring + 26;
    const char *match = find(wiring, end, letter);
    return (end == match) ? -1 : (match - wiring);
}