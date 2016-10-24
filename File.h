#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File {
    private:
        string name;
        string type;
    public:
        File();
        File(string t);
        File(string n, string t);      
        string getName() const;
        string getType() const;
        virtual void output() const = 0;
};
#endif