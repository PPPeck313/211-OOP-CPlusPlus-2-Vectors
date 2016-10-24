#include "File.h"
#include "Text.h"
#include <string>
#include <iostream>

using namespace std;

Text::Text() : File::File(".txt") {
    characters = 0;
    size = getSize();
}

Text::Text(string n, int c) : File::File(n, ".txt") {
    characters = c;
    size = getSize();
}

int Text::getCharacters() const {
    return characters;
}

int Text::getSize() const {
    return ((characters * 8) / 8);
}

void Text::output() const {
    File::output();
    cout<<"Characters: "<<characters<<endl;
    cout<<"Size: "<<size<<" bytes"<<endl<<endl;
}