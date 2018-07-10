#ifndef POINT_HPP
#define POINT_HPP

#include "Base.hpp"

namespace Snake
{
    class Point
    {
    private:
        int8_t m_X = 0;
        int8_t m_Y = 0;

    public:
        Point() = default;
        ~Point()= default;
        Point(const Point&) = default;
        Point(Point&&) = default;
        Point& operator=(const Point&) = default;
        Point& operator=(Point&&) = default;
        Point(int8_t x, int8_t y);

        void move(EDirection ADirection, int8_t ADistance);
        bool isHit(const Point& APoint) const;
    };
}

#endif
