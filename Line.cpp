#include "Line.hpp"

Line::Line(Point ABegin, EDirection ADirection, uint8_t ALength)
{
    m_Points.push_front(ABegin);
    for(int i = 0; i < ALength; i++)
    {
        ABegin.move(ADirection, 1);
        m_Points.push_front(ABegin);
    }
}

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
