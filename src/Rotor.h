#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{

private:
    char* wiring;
    int offset;

public:
    Rotor(char* w, char i);
    void rotate();
    char encode(char letter);
};

#endif // ROTOR_H
