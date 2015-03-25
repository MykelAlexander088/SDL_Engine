#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL/SDL.h>

class Graphics
{
private:
    SDL_Surface* backbuffer;
    int width;
    int height;
public:
    bool init(int aWidth, int aHeight, bool aFullscreen);
    void drawPixel(int x, int y, int r, int g, int b);
    void drawRect(int x, int y, int width, int height, int r, int g, int b);
    void fillRect(int x, int y, int width, int height, int r, int g, int b);
    void clearScreen(int r, int g, int b);
    void flip();

    int getWidth() {return width;}
    int getHeight() { return height;}
    SDL_Surface* getBackbuffer() {return backbuffer;}
};

#endif // GRAPHICS_H
