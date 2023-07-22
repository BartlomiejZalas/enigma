#ifndef WIRING_RING_H
#define WIRING_RING_H

class WiringRing
{

private:
    const char *wiring;
    char findIndex(char letter);

public:
    WiringRing(const char *w);
    WiringRing() = default;
    char encode(char letter, int offset);
    char encodeBack(char letter, int offset);
    
};

#endif // WIRING_RING_H
