#pragma once

#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "spaceship.hpp"

class PlayState : public GameState
{
public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

     PlayState(Game* game);

private:
    Spaceship   player;

    void PauseGame();
};