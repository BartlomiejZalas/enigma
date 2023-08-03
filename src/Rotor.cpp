#include "Rotor.h"
#include "WiringRing.h"
#include "functions.h"

#include <iostream>

using namespace std;

Rotor::Rotor(const char *w, char initialOffset) : offset(charToInt(initialOffset))
{
    this->wiringRing = WiringRing(w);
};

void Rotor::rotate()
{
    ++this->offset;
    if (this->offset == 26)
    {
        this->offset = this->offset % 26;
    }
}

char Rotor::encode(char letter)
{
    return this->wiringRing.encode(letter, this->offset);
}

char Rotor::encodeBack(char letter)
{
    return this->wiringRing.encodeBack(letter, this->offset);
}

int Rotor::getOffset()
{
    return this->offset;
}
