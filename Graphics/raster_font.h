#ifndef RASTER_FONT_H
#define RASTER_FONT_H

#include "image.h"

class RasterFont
{
private:
    static const int NUM_COLUMNS = 16;
    static const int START_CHAR = 32;

    Image image;
    int charSize;
public:
    bool load(char fileName[], Graphics* g);
    void draw(char text[], int x, int y, Graphics* g);
    void free();
};

#endif // RASTER_FONT_H
