#ifndef IMAGE_H
#define IMAGE_H

#include <SDL/SDL.h>
#include "graphics.h"

class Image
{
private:
    SDL_Surface* surface;
    int width;
    int height;
    int frameWidth;
    int frameHeight;

public:
    Image();
    ~Image();
    bool load(char fileName[]);
    bool load(char fileName[], int aFrameWidth, int aFrameHeight);
    void draw(int x, int y, Graphics* g);
    void draw(int x, int y, int frame, Graphics* g);
    void free();

    int getWidth() {return width;}
    int getHeight() {return height;}
    int getFrameWidth() {return frameWidth;}
    int getFrameHeight() {return frameHeight;}
    void setFrameSize(int w, int h){frameWidth = w; frameHeight = h;}
    bool isLoaded(){return (surface != NULL);}
};

#endif // IMAGE_H
