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
    Point Head(m_Points.front());
    Head.move(m_CurrentDirection, 1);    
    m_Points.push_front(Head);
}

void Snake::draw(sf::RenderWindow &ADrawingWindow) const
{
    for(auto point = m_Points.cbegin(); point != m_Points.cend(); ++point)
    {
        sf::Texture texture;
        
        if(point != m_Points.cbegin() && point != --m_Points.cend())
        {
            auto prev = point;
            auto next = point;
            prev--;
            next++;

            Point dNext(point->getX() - next->getX(), point->getY() - next->getY());
            Point dPrev(point->getX() - prev->getX(), point->getY() - prev->getY());

            if(     dNext.getX() != 0 && dPrev.getX() != 0)
                texture = SpriteLoader::getSprite(ESprite::LineHorizontal);
            else if(dNext.getY() != 0 && dPrev.getY() != 0)
                texture = SpriteLoader::getSprite(ESprite::LineVertical);
            else
            {
                Point dSide(dNext.getX() + dPrev.getX(), dNext.getY() + dPrev.getY());
                if(     dSide.getX() == 1   && dSide.getY() == 1)
                    texture = SpriteLoader::getSprite(ESprite::TopLeftCorner);
                else if(dSide.getX() == 1   && dSide.getY() == -1)
                    texture = SpriteLoader::getSprite(ESprite::BottomLeftCorner);
                else if(dSide.getX() == -1  && dSide.getY() == 1)
                    texture = SpriteLoader::getSprite(ESprite::TopRightCorner);
                else if(dSide.getX() == -1  && dSide.getY() == -1)
                    texture = SpriteLoader::getSprite(ESprite::BottomRightCorner);

            }
        }
        else
        {
            auto side = point;
            if(point == m_Points.cbegin())
                side++;
            if(point == --m_Points.cend())
                side--;

            Point dSide(point->getX() - side->getX(), point->getY() - side->getY());
            if(dSide.getY() != 0)
                texture = SpriteLoader::getSprite(ESprite::LineVertical);
            else if(dSide.getX() != 0)
                texture = SpriteLoader::getSprite(ESprite::LineHorizontal);
        }

        sf::Sprite sprite(texture);
        sprite.setColor(sf::Color::Green);
        sprite.setPosition(point->getX() * 16, point->getY() * 16);
        ADrawingWindow.draw(sprite);
    }
}
