#include "Point.hpp"

Point::Point(int16_t x, int16_t y)
    : m_X(x), m_Y(y)
{
    validate();
}

void Point::move(EDirection ADirection, int8_t ADistance)
{
    switch(ADirection)
    {
        case EDirection::Up:
            m_Y -= ADistance;
            break;
        case EDirection::Down:
            m_Y += ADistance;
            break;
        case EDirection::Right:
            m_X += ADistance;
            break;
        case EDirection::Left:
            m_X -= ADistance;
            break;
        default: break;
    }
    validate();
}

void Point::validate()
{
    if(m_X < 0)                 m_X += FIELD_SIZE;
    else if(m_X >= FIELD_SIZE)  m_X -= FIELD_SIZE;
    if(m_Y < 0)                 m_Y += FIELD_SIZE;
    else if(m_Y >= FIELD_SIZE)  m_Y -= FIELD_SIZE;
}

bool Point::isHit(const Point& APoint) const
{
    return (m_X == APoint.m_X && m_Y == APoint.m_Y);
}

void Point::setCoord(int16_t x, int16_t y)
{
    m_X = x;
    m_Y = y;
    validate();
}

int16_t Point::getX() const
{
    return m_X;
}

int16_t Point::getY() const
{
    return m_Y;
}
