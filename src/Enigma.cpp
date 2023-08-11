#include "Enigma.h"
#include <sstream>

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

string Enigma::encode(const string str)
{
    stringstream result;
    for (const char ch : str)
    {
        result << encode(ch);
    }
    return result.str();
}

char Enigma::encode(const char letter)
{
    performRotations();
    return performEncode(letter);
}

void Enigma::performRotations()
{
    this->rotorIII->rotate();

    if (this->rotorIIITurningNoch == this->rotorIII->getOffset())
    {
        this->rotorII->rotate();
    }

    if (this->rotorIITurningNoch == this->rotorII->getOffset())
    {
        this->rotorI->rotate();
    }
}

char Enigma::performEncode(const char letter)
{
    char l = letter;

    l = this->plugboard->encode(l);
    debugLog("PLUGBOARD", l);

    l = this->rotorIII->encode(l);
    debugLog("ROTOR III", l);

    l = this->rotorII->encode(l);
    debugLog("ROTOR II", l);

    l = this->rotorI->encode(l);
    debugLog("ROTOR I", l);

    l = this->reflector->encode(l);
    debugLog("REFLECTOR", l);

    l = this->rotorI->encodeBack(l);
    debugLog("ROTOR I", l);

    l = this->rotorII->encodeBack(l);
    debugLog("ROTOR II", l);

    l = this->rotorIII->encodeBack(l);
    debugLog("ROTOR III", l);

    l = this->plugboard->encode(l);
    debugLog("PLUGBOARD", l);

    return l;
}