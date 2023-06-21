#include <iostream>
#include "src/Rotor.h"
#include "src/functions.h"

using namespace std;

int main()
{
    cout << "Enigma Machine" << endl;

    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');

    cout << endl << " encode test - initial offset A (0)" << endl;

    cout << rotor_I.encode('A') <<" should be E" << endl;

    rotor_I.rotate();

    cout << endl << "encode test - initial offset B (1)" << endl;

    cout << rotor_I.encode('A') <<" should be J" << endl;

    return 0;
}

