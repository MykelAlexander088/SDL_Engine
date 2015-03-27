#include "graphics.h"
#include <cassert>

bool Graphics::init(int aWidth, int aHeight, bool aFullscreen)
{
    bool success = true;
    width = aWidth;
    height = aHeight;
    
    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, aWidth, aHeight, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Could not create SDL Window!\n");
        success = false;
    }
    else
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL)
        {
            printf("Failed to initialize renderer\n");
            success = false;
        }
        else
        {
            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        }
    }

    return success;
}

void Graphics::clearScreen(int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderClear(renderer);;
}

void Graphics::flip()
{
    SDL_RenderPresent(renderer);
}

void Graphics::drawPixel(int x, int y, int r, int g, int b)
{
    assert(renderer != NULL);
    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    if (x > w || x < 0 || y > h || y < 0)
        return;

    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void Graphics::drawRect(int x, int y, int width, int height, int r, int g, int b)
{
    assert(renderer != NULL);
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
}

void Graphics::fillRect(int x, int y, int width, int height, int r, int g, int b)
{
    assert(renderer != NULL);
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
    SDL_RenderFillRect(renderer, &rect);
}

void Graphics::kill()
{
    if (window != NULL)
    {
        SDL_DestroyWindow(window);
    }
}


