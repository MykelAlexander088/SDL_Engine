#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <stack>
#include "game_state.h"
#include "graphics.h"

class GameState;

class StateManager
{
private:
    std::stack<GameState*> states;
public:
    StateManager(){};
    ~StateManager(){};
    
    void addState(GameState* state);
    void popState();
    void update();
    void draw(Graphics* g);
    bool isEmpty();
};

#endif//STATE_MANAGER_H
