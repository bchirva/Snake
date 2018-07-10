#ifndef LINE_HPP
#define LINE_HPP

#include <vector>
#include "Point.hpp"

namespace Snake
{
    class Line
    {
    private:
        std::vector<Point> m_Points;
    public:
        Line() = default;
        ~Line() = default;
        Line(const Line&) = default;
        Line(Line&&) = default;
        Line& operator=(const Line&) = default;
        Line& operator=(Line&&) = default;

        bool isHit(const Point& APoint) const;
        bool isHit(const Line& ALine) const;
    };
}

#endif
