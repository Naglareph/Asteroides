#include "play_state.hpp"
#include "menu_state.hpp"
#include "game_state.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

    // for (unsigned short i = 0; i < 3; i++) {
    //     Asteroid body(0);
    //     this->asteroids.push_back(body);
    // }

void PlayState::draw(const float dt)
{
    game->window.draw(this->ship);

    for (auto var : this->bullets)
        this->game->window.draw(var);
    for (auto var : this->asteroids)
        this->game->window.draw(var);
}

void PlayState::update(const float dt)
{
    ship.update(dt);

    for (auto i = this->bullets.begin(); i != this->bullets.end(); i++) {
        if (i->isAlive()) {
            i->update(dt);
        } else {
            this->bullets.erase(i);
            i--;
        }
    }

    for (auto i = this->asteroids.begin(); i != this->asteroids.end(); i++) {
        if (i->isAlive()) {
            i->update(dt);
        } else {
            this->asteroids.erase(i);
            i--;
        }
    }
}

void PlayState::handleInput()
{
    sf::Event event;

    while (this->game->window.pollEvent(event))
    {
        this->ship.onEvent(event);
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
                    case sf::Keyboard::Space: {
                        Bullet bullet(ship.getPosition(), ship.getRotation());
                        this->bullets.push_back(bullet);
                        break;
                    }
                    default:
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
    for (unsigned short i = 0; i < 3; i++) {
        Asteroid body(0);
        this->asteroids.push_back(body);
    }
}

void PlayState::PauseGame()
{
}
