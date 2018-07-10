#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class IDrawable
{
    public:
        virtual void draw(sf::RenderWindow& ADrawingWindow) const = 0;
};

#endif
