#ifndef POINT_HPP
#define POINT_HPP

#include "Base.hpp"

class Point
{
public:
    Point() = default;
    virtual ~Point()= default;
    Point(const Point&) = default;
    Point(Point&&) = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    Point(int16_t x, int16_t y);

    int16_t getX() const;
    int16_t getY() const;

    void setCoord(int16_t x, int16_t y);
    void move(EDirection ADirection, int8_t ADistance);
    bool isHit(const Point& APoint) const;

protected:
    int16_t m_X = 0;
    int16_t m_Y = 0;

private:
    void validate();
};

#endif
