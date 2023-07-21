#ifndef ROTOR_H
#define ROTOR_H

#include "WiringRing.h"

class Rotor
{

private:
    int offset;
    WiringRing wiringRing;

public:
    Rotor(const char *w, char i);
    void rotate();
    char encode(char letter);
    int getOffset();
};

#endif // ROTOR_H
