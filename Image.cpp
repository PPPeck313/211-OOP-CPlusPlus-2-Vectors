#include "File.h"
#include "Image.h"
#include <string>
#include <iostream>

using namespace std;

Image::Image() : File(".gif") {
    rows = 0;
    columns = 0;
    colorDepth = 0;
    size = getSize();
}

Image::Image(string n, int r, int c, int cD) : File(n, ".gif") {
    rows = r;
    columns = c;
    colorDepth = cD;
    size = getSize();
}

int Image::getSize() const {
    return ((rows * columns * colorDepth) / 8);
}

int Image::getRows() const {
    return rows;
}

int Image::getColumns() const {
    return columns;
}

int Image::getColorDepth() const {
    return colorDepth;
}

void Image::output() const {
    int colors = 1;
    for (int i = 0; i < colorDepth; i++) {
        colors = colors * 2;
    }
    File::output();
    cout<<"Dimensions: "<<rows * columns<<endl;
    cout<<"Colors: "<<colors<<endl;
    cout<<"Size: "<<size<<" bytes"<<endl<<endl;
}