#include "Wall.hpp"

void Wall::draw(sf::RenderWindow& ADrawingWindow) const
{
    (void)(ADrawingWindow);
}

void Wall::expand(Line ALine)
{
    for(auto p: ALine)
    {
        if(!isHit(p))
        {
            m_Points.push_back(p);
        }
    }
}
