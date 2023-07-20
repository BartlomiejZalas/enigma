#ifndef ENIGMA_H
#define ENIGMA_H

#include <memory>
#include "Rotor.h"
#include "Plugboard.h"
#include "functions.h"

using namespace std;

class Enigma
{

private:
    unique_ptr<Rotor> rotorI;
    unique_ptr<Rotor> rotorII;
    unique_ptr<Rotor> rotorIII;

    unique_ptr<Plugboard> plugboard;

    int rotorITurningNoch = charToInt('R');
    int rotorIITurningNoch = charToInt('F');
    int rotorIIITurningNoch = charToInt('W');

public:
    Enigma(
        unique_ptr<Rotor> &r1,
        unique_ptr<Rotor> &r2,
        unique_ptr<Rotor> &r3,
        unique_ptr<Plugboard> &pb);

    char encode(char letter);
};

#endif // ENIGMA_H