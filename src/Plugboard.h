#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <vector>
#include <utility>
#include <map>

using namespace std;

class Plugboard
{

private:
    map<char, char> mapping;

public:
    Plugboard() = default;
    Plugboard(vector<pair<char, char>> pairs);
    char encode(char letter);
};

#endif // PLUGBOARD_H