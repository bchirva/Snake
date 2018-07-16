#include "DeathSpot.hpp"

DeathSpot::DeathSpot(Point APoint)
    : Point(APoint)
{}

void DeathSpot::draw(sf::RenderWindow& ADrawingWindow) const
{
    sf::Sprite sprite(TextureLoader::getTexture(ESprite::Star));
    sprite.setColor(sf::Color::Black);
    sprite.setPosition(m_X * 16, m_Y * 16);
    ADrawingWindow.draw(sprite); 
}
