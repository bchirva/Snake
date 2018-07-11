#include <SpriteLoader.hpp>

sf::Texture SpriteLoader::getSprite(ESprite ARequestedSprite)
{
    auto it = g_Sprites.find(ARequestedSprite);
    if(it != g_Sprites.cend())
        return it->second;
    else
        return sf::Texture();
}

void SpriteLoader::loadSprites()
{
    sf::Image img;
    img.loadFromFile("./resources/img/sprite_sheet.png");
    sf::Texture buff;

    buff.loadFromImage(img, sf::IntRect(0,0,16,16));
    g_Sprites[ESprite::LineVertical] = buff;

    buff.loadFromImage(img, sf::IntRect(0,16,16,16));
    g_Sprites[ESprite::LineHorizontal] = buff;

    buff.loadFromImage(img, sf::IntRect(0,32,16,16));
    g_Sprites[ESprite::BottomRightCorner] = buff;

    buff.loadFromImage(img, sf::IntRect(0,48,16,16));
    g_Sprites[ESprite::BottomLeftCorner] = buff;

    buff.loadFromImage(img, sf::IntRect(0,64,16,16));
    g_Sprites[ESprite::TopRightCorner] = buff;

    buff.loadFromImage(img, sf::IntRect(0,80,16,16));
    g_Sprites[ESprite::TopLeftCorner] = buff;

    buff.loadFromImage(img, sf::IntRect(0,96,16,16));
    g_Sprites[ESprite::LineCross] = buff;

    buff.loadFromImage(img, sf::IntRect(0,112,16,16));
    g_Sprites[ESprite::RightHalfCross] = buff;

    buff.loadFromImage(img, sf::IntRect(0,128,16,16));
    g_Sprites[ESprite::LeftHalfCross] = buff;

    buff.loadFromImage(img, sf::IntRect(0,112,16,16));
    g_Sprites[ESprite::TopHalfCross] = buff;

    buff.loadFromImage(img, sf::IntRect(0,128,16,16));
    g_Sprites[ESprite::BottomHalfCross] = buff;

    buff.loadFromImage(img, sf::IntRect(0,144,16,16));
    g_Sprites[ESprite::Star] = buff;
}
