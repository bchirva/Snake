#ifndef LINE_HPP
#define LINE_HPP

#include <list>
#include "Point.hpp"

class Line
{
public:
    Line() = default;
    virtual ~Line() = default;
    Line(const Line&) = default;
    Line(Line&&) = default;
    Line& operator=(const Line&) = default;
    Line& operator=(Line&&) = default;
    Line(Point ABegin, EDirection ADirection, uint8_t ALength);

    bool isHit(const Point& APoint) const;
    bool isHit(const Line& ALine) const;

    std::list<Point>::iterator begin();
    std::list<Point>::iterator end();
//    auto begin() -> decltype(m_Points.begin());
//    auto end() -> decltype(m_Points.end());
protected:
    std::list<Point> m_Points;
};

#endif
