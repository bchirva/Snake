#ifndef POINT_HPP
#define POINT_HPP

#include "Base.hpp"

class Point
{
private:
    void validate();

protected:
    int8_t m_X = 0;
    int8_t m_Y = 0;

public:
    Point() = default;
    virtual ~Point()= default;
    Point(const Point&) = default;
    Point(Point&&) = default;
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    Point(int8_t x, int8_t y);

    int8_t getX() const;
    int8_t getY() const;

    void setCoord(int8_t x, int8_t y);
    void move(EDirection ADirection, int8_t ADistance);
    bool isHit(const Point& APoint) const;
};

#endif
