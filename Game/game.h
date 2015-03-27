#ifndef GAME_H
#define GAME_H

#include <SDL2_ttf/SDL_ttf.h>
#include "../Graphics/graphics.h"
#include "../Input/input.h"
#include "../Audio/audio.h"

class Game
{
private:
    Graphics graphics;
    Input input;
    Audio audio;
    int fps;
    bool isDone;

public:
    Game();
    ~Game();

    unsigned int getTicks();
    void setFPS(int f);
    void delay(int ticks);
    bool initSystem(char title[], int width, int height, bool fullscreen);
    void freeSystem();
    void run();
    void end();

    virtual bool init();
    virtual void free();
    virtual void update();
    virtual void draw(Graphics* g);

    Graphics* getGraphics();
    Input* getInput();
    Audio* getAudio();
};

#endif // GAME_H
