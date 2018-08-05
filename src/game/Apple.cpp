#include "Apple.hpp"

void Apple::draw(sf::RenderWindow& ADrawingWindow) const
{
    sf::Sprite sprite(TextureLoader::getTexture(ESprite::Star));
    sprite.setColor(sf::Color::Red);
    sprite.setPosition(m_X * 16, m_Y * 16);
    ADrawingWindow.draw(sprite); 
}
