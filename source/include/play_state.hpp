#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "game_state.hpp"
#include "spaceship.hpp"
#include "bullet.hpp"

class PlayState : public GameState
{
public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

     PlayState(Game* game);

private:
    Spaceship   ship;

    std::vector<Bullet> bullets;

    void PauseGame();
};