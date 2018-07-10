#include "Line.hpp"

using Snake::Line;
using Snake::Point;

bool Line::isHit(const Point& APoint) const
{
    for(auto p: m_Points)
    {
        if(p.isHit(APoint))
            return true;
    }
    return false;
}

bool Line::isHit(const Line& ALine) const
{
    for(auto p: m_Points)
    {
        if(ALine.isHit(p))
            return true;
    }
    return false;
}
