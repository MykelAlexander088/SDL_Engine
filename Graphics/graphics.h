#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

class Graphics
{
private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    int width;
    int height;
public:
    bool init(int aWidth, int aHeight, bool aFullscreen);
    void kill();
    void drawPixel(int x, int y, int r, int g, int b);
    void drawRect(int x, int y, int width, int height, int r, int g, int b);
    void fillRect(int x, int y, int width, int height, int r, int g, int b);
    void clearScreen(int r, int g, int b);
    void flip();

    int getWidth() {return width;}
    int getHeight() { return height;}
    SDL_Renderer* getRenderer() {return renderer;}
    SDL_Window* getWindow() {return window;}
};

#endif // GRAPHICS_H
