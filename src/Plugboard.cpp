#include "Plugboard.h"

Plugboard::Plugboard(vector<pair<char, char>> pairs) {
    for(pair<char, char> pair : pairs) {
        this->mapping.insert(make_pair(pair.first, pair.second));
        this->mapping.insert(make_pair(pair.second, pair.first));
    }
};

char Plugboard::encode(char letter)
{
    auto letterMapping = this->mapping.find(letter);
    if (letterMapping == this->mapping.end()) {
        return letter;
    } 
    return letterMapping->second;
}