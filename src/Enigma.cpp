#include "Enigma.h"

using namespace std;

Enigma::Enigma(
    unique_ptr<Rotor> &r1,
    unique_ptr<Rotor> &r2,
    unique_ptr<Rotor> &r3,
    unique_ptr<Plugboard> &pb,
    unique_ptr<Reflector> &r) : rotorI(move(r1)),
                                rotorII(move(r2)),
                                rotorIII(move(r3)),
                                plugboard(move(pb)),
                                reflector(move(r)) {}

char Enigma::encode(const char letter)
{
    this->rotorI->rotate();

    char encodedByPlugboardStart = this->plugboard->encode(letter);
    debugLog("PLUGBOARD", encodedByPlugboardStart);

    char encodedByRotorIII = this->rotorIII->encode(encodedByPlugboardStart);
    debugLog("ROTOR III", encodedByRotorIII);

    if (this->rotorIIITurningNoch == this->rotorIII->getOffset())
    {
        this->rotorII->rotate();
    }

    char encodedByRotorII = this->rotorII->encode(encodedByRotorIII);
    debugLog("ROTOR II", encodedByRotorII);

    if (this->rotorIITurningNoch == this->rotorII->getOffset())
    {
        this->rotorI->rotate();
    }

    char encodedByRotorI = this->rotorI->encode(encodedByRotorII);
    debugLog("ROTOR I", encodedByRotorI);

    char encodedByReflector = this->reflector->encode(encodedByRotorI);
    debugLog("REFLECTOR", encodedByReflector);

    char encodedByRotorIReverse = this->rotorI->encode(encodedByReflector);
    debugLog("ROTOR I", encodedByRotorIReverse);

    char encodedByRotorIIReverse = this->rotorII->encode(encodedByRotorIReverse);
    debugLog("ROTOR II", encodedByRotorIIReverse);

    char encodedByRotorIIIReverse = this->rotorIII->encode(encodedByRotorIIReverse);
    debugLog("ROTOR III", encodedByRotorIIIReverse);

    char encodedByPlugboardEnd = this->plugboard->encode(encodedByRotorIIIReverse);
    debugLog("PLUGBOARD", encodedByPlugboardEnd);

    return encodedByPlugboardEnd;
}