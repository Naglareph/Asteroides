#include "SFML/Graphics.hpp"

#include <iostream>

#include "game.hpp"
#include "menu_state.hpp"
#include "game_state.hpp"
#include "play_state.hpp"

MenuState::MenuState(Game* game)
{
    this->menuScreen.AddResource("MenuImageBackground"); //add MenuImage
    this->menuScreen.AddResource("MenuImageMiddleground"); //add MenuImage
    this->menuScreen.AddResource("MenuImageForground"); //add MenuImage

    // Make the background
    sf::Sprite background;
    //set positions of things
    for (int i = 0; i < this->NUM_IMAGES; i++)
    {
        this->menuSprites.push_back(background);
    }
    this->menuSprites[0].setTexture(*(this->menuScreen.GetResource("MenuImageBackground")));
    this->menuSprites[1].setTexture(*(this->menuScreen.GetResource("MenuImageMiddleground")));
    this->menuSprites[2].setTexture(*(this->menuScreen.GetResource("MenuImageForground")));

    this->menuSprites[3].setTexture(*(this->menuScreen.GetResource("MenuImageMiddleground")));
    this->menuSprites[3].setPosition(sf::Vector2f(1000, 0));
    this->menuSprites[4].setTexture(*(this->menuScreen.GetResource("MenuImageForground")));
    this->menuSprites[4].setPosition(sf::Vector2f(1000, 0));

    //Text stuff
    sf::Text text;
    font.loadFromFile("Assets/fonts/arial.ttf");
    text.setFont(font);
    text.setPosition(100, 100);
    text.setCharacterSize(24); // in pixels, not points!
        // set the color
    text.setFillColor(sf::Color::White);
        // set the text style
    text.setStyle(sf::Text::Bold); 

    //set positions of things
    for (int i = 0; i < this->NUM_BUTTONS; i++)
    {
        this->buttons.push_back(text);
        this->buttons[i].setPosition(text.getPosition().x, text.getPosition().y + i * 100);
    }

    //Since it's only 3 text its fine to just manually set each...
    this->buttons[0].setString("Play Game");
    this->buttons[1].setString("Options");
    this->buttons[2].setString("Quit");

    this->game = game; 
}

void MenuState::handleInput()
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
            /* Change Between game states */
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    this->game->window.close();
                else if (event.key.code == sf::Keyboard::Enter)
                    loadgame();
                break;
            case sf::Event::MouseMoved:
                if (isTextClicked(buttons[0]))
                    this->buttons[0].setFillColor(sf::Color::Red);
                else
                    this->buttons[0].setFillColor(sf::Color::White);
                if (isTextClicked(buttons[1]))
                    this->buttons[1].setFillColor(sf::Color::Red);
                else
                    this->buttons[1].setFillColor(sf::Color::White);
                if (isTextClicked(buttons[2]))
                    this->buttons[2].setFillColor(sf::Color::Red);
                else
                    this->buttons[2].setFillColor(sf::Color::White);
                break;
            default:
                break;
        }
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (isTextClicked(buttons[0]))
            loadgame();
        else if (isTextClicked(buttons[2]))
            this->game->window.close();   
    }
}

void MenuState::update(const float dt)
{
    this->animateBackground();
}

void MenuState::draw(const float dt)
{
    for (auto var : this->menuSprites)
        this->game->window.draw(var);
    for (auto var : this->buttons)
        this->game->window.draw(var);
}

bool MenuState::isTextClicked(sf::Text text) 
{
    sf::IntRect rect(text.getPosition().x, text.getPosition().y, text.getGlobalBounds().width, text.getGlobalBounds().height);

    //If mouse position is in the rectangle do whatever
    if (rect.contains(sf::Mouse::getPosition(game->window)))
        return true;

    //Otherwise, don't do anything
    return false;
}

void MenuState::loadgame()
{
    game->pushState(new PlayState(game));
}

void			MenuState::animateBackground()
{ 
    for (int i = 1; i <= 4; i++) {
        if (i == 1 || i == 3) {
            this->menuSprites[i].move(-2, 0);
        } else {
            this->menuSprites[i].move(-0.5, 0);
        }
        if (this->menuSprites[i].getPosition() == sf::Vector2f(-1000, 0))
            this->menuSprites[i].setPosition(sf::Vector2f(1000, 0));
    }
}