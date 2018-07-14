#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <mutex>
#include "Line.hpp"
#include "Drawable.hpp"

class Snake : public Line, public IDrawable
{
private:
    EDirection m_CurrentDirection;
    EDirection m_NextDirection;
    std::mutex m_DirectionMutex;
public:
    Snake(Point ABegin, EDirection ADirection);
    ~Snake() = default;
    
    void turn(EDirection ADirection);
    void draw(sf::RenderWindow& ADrawingWindow) const override;

    void move();
    void eat();
    Point aboutToMove();
};

#endif
