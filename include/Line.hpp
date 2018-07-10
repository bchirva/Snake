#ifndef LINE_HPP
#define LINE_HPP

#include <list>
#include "Point.hpp"

class Line
{
protected:
    std::list<Point> m_Points;
public:
    Line() = default;
    ~Line() = default;
    Line(const Line&) = default;
    Line(Line&&) = default;
    Line& operator=(const Line&) = default;
    Line& operator=(Line&&) = default;
    Line(Point ABegin, EDirection ADirection, uint8_t ALength);

    bool isHit(const Point& APoint) const;
    bool isHit(const Line& ALine) const;
};

#endif
