#include "Enigma.h"

using namespace std;

Enigma::Enigma(
    unique_ptr<Rotor> &r1,
    unique_ptr<Rotor> &r2,
    unique_ptr<Rotor> &r3,
    unique_ptr<Plugboard> &pb) : rotorI(move(r1)),
                                 rotorII(move(r2)),
                                 rotorIII(move(r3)),
                                 plugboard(move(pb)) {}

char Enigma::encode(const char letter)
{
    this->rotorI->rotate();

    char encodedByPlugboardStart = this->plugboard->encode(letter);

    char encodedByRotorIII = this->rotorIII->encode(encodedByPlugboardStart);

    if (this->rotorIIITurningNoch == this->rotorIII->getOffset())
    {
        this->rotorII->rotate();
    }

    char encodedByRotorII = this->rotorII->encode(encodedByRotorIII);

    if (this->rotorIITurningNoch == this->rotorII->getOffset())
    {
        this->rotorI->rotate();
    }

    char encodedByRotorI = this->rotorI->encode(encodedByRotorII);

    // TODO Add reflector here as suggested here:
    // UKW-B	YRUHQSLDPXNGOKMIEBFZCWVJAT
    // https://www.cryptomuseum.com/crypto/enigma/wiring.htm

    char encodedByRotorIIReverse = this->rotorII->encode(encodedByRotorI);

    char encodedByRotorIIIReverse = this->rotorIII->encode(encodedByRotorIIReverse);

    char encodedByPlugboardEnd = this->plugboard->encode(encodedByRotorIIIReverse);
}