#include "Snake.hpp"

Snake::Snake(Point ABegin, EDirection ADirection)
    : Line(ABegin, ADirection, 4),
      m_CurrentDirection(ADirection),
      m_NextDirection(ADirection)
{}

void Snake::turn(EDirection ADirection)
{
    std::lock_guard<std::mutex> lock(m_DirectionMutex);
    if(ADirection == m_NextDirection)
        return;

    if ((ADirection == EDirection::Top      && m_CurrentDirection == EDirection::Down) ||
        (ADirection == EDirection::Down   && m_CurrentDirection == EDirection::Top)    ||
        (ADirection == EDirection::Left     && m_CurrentDirection == EDirection::Right)  ||
        (ADirection == EDirection::Right    && m_CurrentDirection == EDirection::Left))
        return;

    m_NextDirection = ADirection;
}

Point Snake::aboutToMove() 
{
    std::lock_guard<std::mutex> lock_dir(m_DirectionMutex);
    m_CurrentDirection = m_NextDirection;
    std::lock_guard<std::recursive_mutex> lock_line(m_PointsMutex);
    Point Head(m_Points.front());
    Head.move(m_CurrentDirection, 1);    
    return Head;
}

void Snake::eat()
{
    std::lock_guard<std::recursive_mutex> lock(m_PointsMutex);
    m_Points.push_front(aboutToMove());
}

void Snake::move()
{
    std::lock_guard<std::recursive_mutex> lock(m_PointsMutex);
    eat();
    m_Points.pop_back();
}

void Snake::draw(sf::RenderWindow &ADrawingWindow) const
{
    std::lock_guard<std::recursive_mutex> lock(m_PointsMutex);
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
                texture = TextureLoader::getTexture(ESprite::LineHorizontal);
            else if(dNext.getY() != 0 && dPrev.getY() != 0)
                texture = TextureLoader::getTexture(ESprite::LineVertical);
            else
            {
                Point dSide(dNext.getX() + dPrev.getX(), dNext.getY() + dPrev.getY());
                if(     dSide.getX() == 1   && dSide.getY() == 1)
                    texture = TextureLoader::getTexture(ESprite::TopLeftCorner);
                else if(dSide.getX() == 1   && dSide.getY() == FIELD_SIZE - 1)
                    texture = TextureLoader::getTexture(ESprite::BottomLeftCorner);
                else if(dSide.getX() == FIELD_SIZE - 1  && dSide.getY() == 1)
                    texture = TextureLoader::getTexture(ESprite::TopRightCorner);
                else if(dSide.getX() == FIELD_SIZE - 1  && dSide.getY() == FIELD_SIZE - 1)
                    texture = TextureLoader::getTexture(ESprite::BottomRightCorner);
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
                texture = TextureLoader::getTexture(ESprite::LineVertical);
            else if(dSide.getX() != 0)
                texture = TextureLoader::getTexture(ESprite::LineHorizontal);
        }

        sf::Sprite sprite(texture);
        sprite.setColor(sf::Color(0, 96, 0));
        sprite.setPosition(point->getX() * 16, point->getY() * 16);
        ADrawingWindow.draw(sprite);
    }
}
