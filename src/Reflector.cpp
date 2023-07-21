#include "Reflector.h"

#include <iostream>

using namespace std;

Reflector::Reflector(const char *w)
{
    this->wiringRing = WiringRing(w);
};

char Reflector::encode(char letter)
{
    return this->wiringRing.encode(letter, 0);
}
