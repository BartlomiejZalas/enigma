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
    int letterIndex = charToInt(letter) + offset;
    char letterToFind = letterIndex % 26 == 0 ? intToChar(26) : intToChar(letterIndex % 26);
    int wiringToIndex = this->findIndex(letterToFind);
    char wiringToLetter = intToChar(wiringToIndex + 1);
    int wiringShift = charToInt(wiringToLetter) - charToInt(letterToFind);
    int encodedLetterIndex = charToInt(letter) + wiringShift;
   
    return encodedLetterIndex % 26 == 0 ? intToChar(26) : intToChar(encodedLetterIndex % 26);
}

int WiringRing::findIndex(char letter)
{
    const char *end = wiring + 26;
    const char *match = find(wiring, end, letter);
    if (end == match)
    {
        throw invalid_argument("no wiring mapping for: " + letter);
    }
    return match - wiring;
}