#include <iostream>
#include "src/Rotor.h"
#include "src/functions.h"

using namespace std;

int main()
{
    cout << "Enigma Machine" << endl;
    cout << endl << " charToInt test" << endl;
    cout << charToInt('A') <<" should be 1" << endl;
    cout << charToInt('B') <<" should be 2" << endl;
    cout << charToInt('Z') <<" should be 26" << endl;

    cout << endl<<"intToChar test" << endl;
    cout << intToChar(1) <<" should be A" << endl;
    cout << intToChar(2) <<" should be B" << endl;
    cout << intToChar(26) <<" should be Z" << endl;

    cout <<endl << endl;


    Rotor rotor_I("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'A');

    cout << endl << " encode test - initial offset A (0)" << endl;

    cout << rotor_I.encode('A') <<" should be E" << endl;
    cout << rotor_I.encode('B') <<" should be K" << endl;
    cout << rotor_I.encode('C') <<" should be M" << endl;
    cout << rotor_I.encode('D') <<" should be F" << endl;
    cout << rotor_I.encode('E') <<" should be L" << endl;
    cout << rotor_I.encode('F') <<" should be G" << endl;
    cout << rotor_I.encode('G') <<" should be D" << endl;
    cout << rotor_I.encode('H') <<" should be Q" << endl;
    cout << rotor_I.encode('I') <<" should be V" << endl;
    cout << rotor_I.encode('J') <<" should be Z" << endl;
    cout << rotor_I.encode('K') <<" should be N" << endl;
    cout << rotor_I.encode('L') <<" should be T" << endl;
    cout << rotor_I.encode('M') <<" should be O" << endl;
    cout << rotor_I.encode('N') <<" should be W" << endl;
    cout << rotor_I.encode('O') <<" should be Y" << endl;
    cout << rotor_I.encode('P') <<" should be H" << endl;
    cout << rotor_I.encode('Q') <<" should be X" << endl;
    cout << rotor_I.encode('R') <<" should be U" << endl;
    cout << rotor_I.encode('S') <<" should be S" << endl;
    cout << rotor_I.encode('T') <<" should be P" << endl;
    cout << rotor_I.encode('U') <<" should be A" << endl;
    cout << rotor_I.encode('W') <<" should be B" << endl;
    cout << rotor_I.encode('X') <<" should be R" << endl;
    cout << rotor_I.encode('Y') <<" should be C" << endl;
    cout << rotor_I.encode('Z') <<" should be J" << endl;

    rotor_I.rotate();

    cout << endl << "encode test - initial offset B (1)" << endl;

    cout << rotor_I.encode('A') <<" should be J" << endl;
    cout << rotor_I.encode('B') <<" should be L" << endl;
    cout << rotor_I.encode('C') <<" should be E" << endl;

    return 0;
}

