#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state_manager.h"
#include "graphics.h"

class StateManager;

class GameState
{
private:
    StateManager* stateManager;
public:
    GameState();
    ~GameState();
    
    virtual void update();
    virtual void draw(Graphics* g);
    
    StateManager* getStateManager();
    void setStateManager(StateManager* sm);
};

#endif//GAME_STATE_H
