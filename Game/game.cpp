#include "game.h"

Game::Game() :
    fps(30),
    isDone(false)
{

}

Game::~Game()
{

}

bool Game::initSystem(char title[], int width, int height, bool fullscreen)
{
    if (SDL_Init( SDL_INIT_EVERYTHING) == -1)
    {
        printf("failed to initialize SDL!\n");
        return false;
    }

    if (!graphics.init(width, height, fullscreen))
    {
        printf("failed to initialize graphics!\n");
        return false;
    }

    SDL_WM_SetCaption(title,NULL);

    if (!audio.init())
    {
        printf("failed to initialize audio!\n");
        return false;
    }
    input.init();

    if (!TTF_Init() == -1)
    {
        printf("TTF failed to init!\n");
        return false;
    }

    return true;
}

void Game::run()
{
    while (!isDone)
    {
        unsigned int frameStart = SDL_GetTicks();
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isDone = true;
                break;
            }
        }
        input.update();
        update();
        draw(getGraphics());
        getGraphics()->flip();

        int frameTime = getTicks()-frameStart;
        int delayTime = (1000/fps)-frameTime;
        delay(delayTime);
    }
    free();
    freeSystem();
}

void Game::freeSystem()
{
    input.kill();
    audio.kill();
    TTF_Quit();
    SDL_Quit();
}

void Game::end()
{
    isDone = true;
}

bool Game::init()
{
    return initSystem("default game. Override init method!", 800, 600, false);
}

void Game::free()
{

}

void Game::update()
{

}

void Game::draw(Graphics* g)
{

}

void Game::setFPS(int f)
{
    fps = f;
}

unsigned int Game::getTicks()
{
    return SDL_GetTicks();
}

void Game::delay(int ticks)
{
    if (ticks > 0)
        SDL_Delay(ticks);
}

Graphics* Game::getGraphics()
{
    return &graphics;
}

Input* Game::getInput()
{
    return &input;
}

Audio* Game::getAudio()
{
    return &audio;
}
