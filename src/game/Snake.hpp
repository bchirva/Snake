#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <mutex>
#include "Line.hpp"
#include "Drawable.hpp"

class Snake : public Line, public IDrawable
{
public:
    Snake(Point ABegin, EDirection ADirection);
    ~Snake() = default;
    
    void draw(sf::RenderWindow& ADrawingWindow) const override;
    bool isHitSelf() const;

    void turn(EDirection ADirection);
    void move();
    const Point& aboutToMove();

private:
    EDirection m_CurrentDirection;
    EDirection m_NextDirection;
    std::mutex m_DirectionMutex;
    mutable std::recursive_mutex m_PointsMutex;
};

#endif
