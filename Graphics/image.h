#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>
#include "graphics.h"

class Image
{
private:
    SDL_Texture* texture;
    int width;
    int height;
    int frameWidth;
    int frameHeight;

public:
    Image();
    ~Image();
    bool load(char fileName[], Graphics* g);
    bool load(char fileName[], Graphics* g, int aFrameWidth, int aFrameHeight);
    void draw(int x, int y, Graphics* g);
    void draw(int x, int y, int frame, Graphics* g);
    void free();

    int getWidth() {return width;}
    int getHeight() {return height;}
    int getFrameWidth() {return frameWidth;}
    int getFrameHeight() {return frameHeight;}
    void setFrameSize(int w, int h){frameWidth = w; frameHeight = h;}
    bool isLoaded(){return (texture != NULL);}
};

#endif // IMAGE_H
