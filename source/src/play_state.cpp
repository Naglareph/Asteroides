#include "play_state.hpp"
#include "menu_state.hpp"
#include "game_state.hpp"

#include "spaceship.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

void PlayState::draw(const float dt)
{
    game->window.draw(this->player);
}

void PlayState::update(const float dt)
{
    player.update(dt);
}

void PlayState::handleInput()
{
    sf::Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
                this->game->window.close();
                break;
            //pause game
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        this->game->window.close();
                        break;
                    default:
                        this->player.onEvent(event);
                        break;
                }
                break;
            default:
                break;
        }
    }


}

PlayState::PlayState(Game* game)
{
    this->game = game;
}

void PlayState::PauseGame()
{
}
