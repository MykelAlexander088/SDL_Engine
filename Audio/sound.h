#ifndef SOUND_H
#define SOUND_H

#include "audio.h"

class Sound
{
private:
    Mix_Chunk* sound;
public:
    Sound();
    ~Sound();
    bool load(char fileName[]);
    void free();

    int play(int loops = 0);
    bool isLoaded();
};
#endif // SOUND_H
