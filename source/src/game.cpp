#include "SFML/Graphics.hpp"
#include "game.hpp"
#include "game_state.hpp"
#include "constants.hpp"

Game::Game()
{
    window.create(sf::VideoMode( APP_WIDTH, APP_HEIGHT), "Asteroides");
    window.setFramerateLimit(APP_FPS);
    window.setKeyRepeatEnabled(true);
}

Game::~Game()
{
    while (!states.empty())
        popState();
}

void Game::pushState(GameState* state)
{
    states.push_back(state);
}

void Game::popState()
{
    states.back();
    delete states.back();
    states.pop_back();
}

GameState* Game::CurrentState()
{
    if (states.empty()) 
        return nullptr;
    else
        return states.back();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        //control frame rate
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        //exception handling
        if (CurrentState() == nullptr) 
            continue;

        //get user input for current game state
        CurrentState()->handleInput();

        //update anything neccessary
        CurrentState()->update(dt);

        //clear window
        window.clear();

        //draw anything in the current game state
        CurrentState()->draw(dt);

        window.display();
    }
}
