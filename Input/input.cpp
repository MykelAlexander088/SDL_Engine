#include "input.h"

void Input::init(SDL_Window* aWindow)
{
    const Uint8* keyboard = SDL_GetKeyboardState(&numKeys);
    keys = new bool[numKeys];
    prevKeys = new bool[numKeys];
    window = aWindow;

    for (int i = 0; i < numKeys; ++i)
    {
        keys[i] = keyboard[i];
        prevKeys[i] = false;
    }

    SDL_GetMouseState(&mouseX, &mouseY);
    for (int i = 1; i <= 3; ++i)
    {
        mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
        prevMouseKeys[i] = false;
    }
}

void Input::update()
{
    const Uint8* keyboard = SDL_GetKeyboardState(&numKeys);
    for (int i = 0; i < numKeys; ++i)
    {
        prevKeys[i] = keys[i];
        keys[i] = keyboard[i];
    }

    SDL_GetMouseState(&mouseX, &mouseY);
    for (int i = 1; i <= 3; ++i)
    {
        prevMouseKeys[i] = mouseKeys[i];
        mouseKeys[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
    }
}

void Input::kill()
{
    delete[] keys;
    delete[] prevKeys;
}

bool Input::mouseDown(int key)
{
    if (key < 0 || key > 3)
        return false;
    return mouseKeys[key];
}

bool Input::mouseHit(int key)
{
    if (key < 0 || key > 3)
        return false;
    return (mouseKeys[key] && !prevMouseKeys[key]);
}

bool Input::mouseUp(int key)
{
    if (key < 0 || key > 3)
        return false;
    return (!mouseKeys[key] && prevMouseKeys[key]);
}

int Input::getMouseX()
{
    return mouseX;
}

int Input::getMouseY()
{
    return mouseY;
}

void Input::setMousePos(int x, int y)
{
    if (window != NULL)
        SDL_WarpMouseInWindow(window, x, y);
}

void Input::hideCursor(bool hide)
{
    if (hide)
        SDL_ShowCursor(SDL_DISABLE);
    else
        SDL_ShowCursor(SDL_ENABLE);
}

bool Input::keyDown(int key)
{
    if (key < 0 || key > numKeys)
        return false;
        return keys[key];
}

bool Input::keyHit(int key)
{
    if (key < 0 || key > numKeys)
        return false;
    return (keys[key] && !prevKeys[key]);
}

bool Input::keyUp(int key)
{

    if (key < 0 || key > numKeys)
        return false;
    return (!keys[key] && prevKeys[key]);
}
