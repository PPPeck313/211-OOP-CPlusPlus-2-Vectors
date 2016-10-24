#include "File.h"
#include <iostream>
#include <string>

using namespace std;

File::File() {
    name = "";
    type = "";
}

File::File(string t) {
    name = "";
    type = t;
}

File::File(string n, string t) {
    name = n;
    type = t;
}

string File::getName() const {
    return name;
}

string File::File::getType() const {
    return type;
}

void File::output() const {
    cout<<"Name: "<<name<<endl;
    cout<<"Type: "<<type<<endl;
}