#ifndef APPLE_HPP
#define APPLE_HPP

#include "Point.hpp"
#include "Drawable.hpp"

class Apple : public Point, public IDrawable
{
public:
    Apple() = default;
    ~Apple() = default;

    void draw(sf::RenderWindow& ADrawingWindow) const override;
};

#endif
