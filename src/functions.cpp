#include <iostream>

using namespace std;

int charToInt(char letter)
{
    return letter - 'A' + 1;
}

char intToChar(int letter)
{
    return (char)(letter + 'A' - 1);
}

void debugLog(string place, char value)
{
    cout << "Encoded by " << place << ": " << value << endl;
}
