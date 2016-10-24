#ifndef TEXT_H
#define TEXT_H

#include "File.h"
#include <string>

using namespace std;

class Text : public File {
    private:
       int characters; 
       int size;
    public:
        Text();
        Text(string n, int c);
        int getSize() const;
        int getCharacters() const;
        void output() const;
};
#endif