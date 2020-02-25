#pragma once

#include <math.h>
#include <SFML/Graphics.hpp>

#include "constants.hpp"

class Bullet: public sf::Drawable, public sf::Transformable {
    static const float lifetime;
    static const float speed;

    public:
        Bullet(sf::Vector2f position, float angle);
        ~Bullet();

        bool isAlive() const noexcept;
        void kill() noexcept;
        void update(const float frametime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        bool is_alive;
        float remaining_life;
        sf::Vector2f direction;
};