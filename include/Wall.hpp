#ifndef WALL_HPP
#define WALL_HPP

#include "Line.hpp"
#include "Drawable.hpp"

class Wall : public Line, public IDrawable
{
public:
    Wall() = default;
    ~Wall() = default;

    void expand(Line ALine);
    void draw(sf::RenderWindow& ADrawingWindow) const override;
};

#endif
