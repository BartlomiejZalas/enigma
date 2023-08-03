#include <iostream>

using namespace std;

int charToInt(char letter)
{
    return letter - 'A';
}

char intToChar(int letter)
{
    return (char)(letter + 'A');
}

void debugLog(string place, char value)
{
    cout << "Encoded by " << place << ": " << value << endl;
}
