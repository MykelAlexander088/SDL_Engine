#include "outline_font.h"

OutlineFont::OutlineFont() :
    font(NULL)
{

}

OutlineFont::~OutlineFont()
{

}

bool OutlineFont::load(char fileName[], int size)
{
    font = TTF_OpenFont(fileName, size);

    if (font == NULL)
    {
        return false;
    }

    return true;
}

void OutlineFont::free()
{
    if (font != NULL)
    {
        TTF_CloseFont(font);
    }
}

//EXPENSIVE (optimization needed)
void OutlineFont::draw(char text[], int x, int y, int r, int g, int b, Graphics* gfx)
{
    if (font == NULL)
        return;

    SDL_Surface* renderedText = NULL;
    SDL_Texture* textTexture = NULL;
    SDL_Color color;
    color.r = r;
    color.g = g;
    color.b = b;
    renderedText = TTF_RenderText_Solid(font, text, color);
    textTexture = SDL_CreateTextureFromSurface(gfx->getRenderer(), renderedText);
    
    SDL_Rect pos = {x, y, renderedText->w, renderedText->h};
    SDL_RenderCopy(gfx->getRenderer(), textTexture, NULL, &pos);
    
    SDL_FreeSurface(renderedText);
    SDL_DestroyTexture(textTexture);
}
