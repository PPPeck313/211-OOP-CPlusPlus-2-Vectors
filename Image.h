#ifndef IMAGE_H
#define IMAGE_H

#include "File.h"
#include <string>

using namespace std;

class Image : public File {
    private:
        int rows;
        int columns;
        int colorDepth;
        int size;
    public:
        Image();
        Image(string n, int r, int c, int cD);
        int getSize() const;
        int getRows() const;
        int getColumns() const;
        int getColorDepth() const;
        void output() const;
};
#endif