#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Line.hpp"

class Snake : public Line
{
private:
    EDirection m_CurrentDirection;
    EDirection m_NextDirection;
public:
    Snake(Point ABegin, EDirection ADirection);
    ~Snake() = default;
    
    void turn(EDirection ADirection);

    void makeStep();
};

#endif
