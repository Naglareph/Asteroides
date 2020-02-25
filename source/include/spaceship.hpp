#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>
#include "constants.hpp"

class Spaceship: public sf::Drawable, public sf::Transformable {
    static const float acceleration;
    static const float max_speed;
    static const float rotation_speed;
    static const float gravity;

    public:
        Spaceship();
        ~Spaceship();

        void reset();
        void update(float);
        void draw(sf::RenderTarget&, sf::RenderStates) const;
        void onEvent(const sf::Event&);

    private:
        sf::Vector2f    speed;
        sf::ConvexShape shape;
        int h_move, v_move;
};