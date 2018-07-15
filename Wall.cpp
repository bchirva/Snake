#include "Wall.hpp"

void Wall::draw(sf::RenderWindow& ADrawingWindow) const
{
    for (auto point: m_Points)
    {
        sf::Texture texture;
        sf::Sprite sprite;

        bool isTop      = isHit(Point(point.getX(),     point.getY() - 1));
        bool isBottom   = isHit(Point(point.getX(),     point.getY() + 1));
        bool isLeft     = isHit(Point(point.getX() - 1, point.getY()));
        bool isRight    = isHit(Point(point.getX() + 1, point.getY()));
        ESprite TargetTexture;

        if (isTop && isBottom && !isLeft && !isRight)           TargetTexture = ESprite::LineVertical;
        else if (isLeft && isRight && !isTop && !isBottom)      TargetTexture = ESprite::LineHorizontal;
        else if (isLeft && isRight && isTop && !isBottom)       TargetTexture = ESprite::TopHalfCross;
        else if (isLeft && isRight && !isTop && isBottom)       TargetTexture = ESprite::BottomHalfCross;
        else if (isLeft && !isRight && isTop && isBottom)       TargetTexture = ESprite::LeftHalfCross;
        else if (!isLeft && isRight && isTop && isBottom)       TargetTexture = ESprite::RightHalfCross;
        else if (isLeft && !isRight && isTop && !isBottom)      TargetTexture = ESprite::TopLeftCorner;
        else if (isLeft && !isRight && !isTop && isBottom)      TargetTexture = ESprite::BottomLeftCorner;
        else if (!isLeft && isRight && isTop && !isBottom)      TargetTexture = ESprite::TopRightCorner;
        else if (!isLeft && isRight && !isTop && isBottom)      TargetTexture = ESprite::BottomRightCorner;
        else /*if (isLeft && isRight && isTop && isBottom)*/    TargetTexture = ESprite::LineCross;

        texture = TextureLoader::getTexture(TargetTexture);
        sprite.setTexture(texture);
        sprite.setColor(sf::Color(128, 128, 128));
        sprite.setPosition(point.getX() * 16, point.getY() * 16);
        ADrawingWindow.draw(sprite);
    } 
}

void Wall::expand(Line ALine)
{
    for(auto p: ALine)
    {
        if(!isHit(p))
        {
            m_Points.push_back(p);
        }
    }
}
