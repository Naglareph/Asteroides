#pragma once
#include "SFML/Graphics.hpp"
#include "resource_manager.hpp"

class TextureManager: public ResourceManager<TextureManager, sf::Texture>
{
public:
    TextureManager(): ResourceManager("Assets/textures/index.txt") {}

    sf::Texture* Load(const std::string& fileName)
    {
        sf::Texture* text = new sf::Texture(); //allocate memory on heap

        //if load fails just delete allocated memory and reset it to NULL.
        if (!text->loadFromFile("Assets/textures/" + fileName))
        {
            delete text;
            text = NULL;
            std::cerr << "failed to load texture" << std::endl;
        }
       
        //otherwise return the texture
        return text;
    }
};