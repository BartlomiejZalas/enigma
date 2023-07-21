#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "WiringRing.h"

class Reflector
{

private:
    const char *wiring;
    WiringRing wiringRing;

public:
    Reflector(const char *w);
    char encode(char letter);
};

#endif // REFLECTOR_H
