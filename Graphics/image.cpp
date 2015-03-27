#include "image.h"
#include <SDL2_image/SDL_image.h>

Image::Image() :
    texture(NULL),
    width(0),
    height(0),
    frameWidth(0),
    frameHeight(0)
{

}

Image::~Image()
{

}

bool Image::load(char fileName[], Graphics* g)
{
    SDL_Surface* imageLoaded = NULL;
    SDL_Texture* textureLoaded = NULL;
    
    imageLoaded = IMG_Load(fileName);

    if (imageLoaded != NULL)
    {
        SDL_SetColorKey(imageLoaded, SDL_TRUE, SDL_MapRGB(imageLoaded->format, 0xFF, 0x00, 0xFF));
        width = imageLoaded->w;
        height = imageLoaded->h;
        textureLoaded = SDL_CreateTextureFromSurface(g->getRenderer(), imageLoaded);
        if (textureLoaded != NULL)
        {
            texture = textureLoaded;
        }
        else
        {
            printf("could not load texture for image: ");
            printf(fileName);
            printf("\n");
            return false;
        }
        SDL_FreeSurface(imageLoaded);
    }
    else
    {
        printf("Failed to load image: ");
        printf(fileName);
        printf("\n");
        return false;
    }
    return true;
}

bool Image::load(char fileName[], Graphics* g, int aFrameWidth, int aFrameHeight)
{
    if (load(fileName, g))
    {
        frameWidth = aFrameWidth;
        frameHeight = aFrameHeight;

        return true;
    }
    return false;
}

void Image::free()
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void Image::draw(int x, int y, Graphics* g)
{
    if (texture == NULL)
        return;
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(g->getRenderer(), texture, NULL, &destRect);
}

void Image::draw(int x, int y, int frame, Graphics* g)
{
    SDL_Rect destRect = {x, y, frameWidth, frameHeight};
    int columns = width/frameWidth;
    SDL_Rect sourceRect = {(frame%columns)*frameWidth, (frame/columns)*frameHeight,
                            frameWidth, frameHeight};
    SDL_RenderCopy(g->getRenderer(), texture, &sourceRect, &destRect);
}
