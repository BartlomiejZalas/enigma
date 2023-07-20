#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{

private:
    const char *wiring;
    int offset;

public:
    Rotor(const char *w, char i);
    void rotate();
    char encode(char letter);
    int getOffset();
};

#endif // ROTOR_H
