#include "Snake.hpp"

Snake::Snake(Point ABegin, EDirection ADirection)
    : Line(ABegin, ADirection, 4),
      m_CurrentDirection(ADirection),
      m_NextDirection(ADirection)
{}

void Snake::turn(EDirection ADirection)
{
    if(ADirection == m_NextDirection)
        return;

    if ((ADirection == EDirection::Top      && m_CurrentDirection == EDirection::Bottom) ||
        (ADirection == EDirection::Bottom   && m_CurrentDirection == EDirection::Top)    ||
        (ADirection == EDirection::Left     && m_CurrentDirection == EDirection::Right)  ||
        (ADirection == EDirection::Right    && m_CurrentDirection == EDirection::Left))
        return;

    m_NextDirection = ADirection;
}

void Snake::makeStep()
{
    m_CurrentDirection = m_NextDirection;
    Point Head(*(m_Points.cbegin()));
    
    Head.move(m_CurrentDirection, 1);    
    m_Points.push_front(Head);
}

void Snake::draw(sf::RenderWindow &ADrawingWindow) const
{
    sf::RectangleShape block(sf::Vector2f(32.0f, 32.0f));
    block.setFillColor(sf::Color(0,100,0));
    
    for(auto p: m_Points)
    {
        block.setPosition(p.getX(), p.getY());
        ADrawingWindow.draw(block); 
    }
}
