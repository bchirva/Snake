#ifndef DEATHSPOT_HPP
#define DEATHSPOT_HPP

#include <Point.hpp>
#include <Drawable.hpp>

class DeathSpot : public Point, public IDrawable
{
public:
    DeathSpot(Point APoint);
    ~DeathSpot() = default;

    void draw(sf::RenderWindow& ADrawingWindow) const override;
};

#endif
