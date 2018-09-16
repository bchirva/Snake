#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "TextureLoader.hpp"

class IDrawable
{
public:
    virtual ~IDrawable() = default;
    virtual void draw(sf::RenderWindow& ADrawingWindow) const = 0;
};

#endif
