#include "Apple.hpp"

void Apple::draw(sf::RenderWindow& ADrawingWindow) const
{
    sf::Sprite sprite(SpriteLoader::getSprite(ESprite::Star));
    sprite.setColor(sf::Color::Red);
    sprite.setPosition(m_X * 16, m_Y * 16);
    ADrawingWindow.draw(sprite); 
}
