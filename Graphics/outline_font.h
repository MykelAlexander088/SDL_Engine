#ifndef OUTLINE_FONT_H
#define OUTLINE_FONT_H

#include <SDL2_ttf/SDL_ttf.h>
#include "graphics.h"

class OutlineFont
{
private:
    TTF_Font* font;
public:
    OutlineFont();
    ~OutlineFont();

    bool load(char fileName[], int size);
    void free();
    void draw(char text[], int x, int y, int r, int g, int b, Graphics* gfx);
};
#endif // OUTLINE_FONT_H
