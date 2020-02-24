#pragma once
#include <SFML/Graphics.hpp>

#include "texture_manager.hpp"
#include "game_state.hpp"

class MenuState : public GameState
{
public: 
    MenuState(Game* game);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

private:

    const unsigned short int NUM_BUTTONS = 3;
    const unsigned short int NUM_IMAGES = 5;
    
    sf::View                view;
    std::vector<sf::Sprite> menuSprites;
    sf::Font                font;
    
    TextureManager          menuScreen;  //menuScreen variable
    
    std::vector<sf::Text>   buttons;
    
    bool    isTextClicked(sf::Text text);
    void    loadgame();
    void    animateBackground();
};
