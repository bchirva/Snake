#include <SpriteLoader.hpp>
#include <iostream>

std::map<ESprite, sf::Texture> SpriteLoader::g_Sprites;

const sf::Texture& SpriteLoader::getSprite(ESprite ARequestedSprite)
{
    auto it = g_Sprites.find(ARequestedSprite);
    return it->second;
}

bool SpriteLoader::loadSprites()
{
    sf::Image img;
    if(!img.loadFromFile("./resources/img/sprite_sheet.png"))
    {
        g_Sprites.clear();
        return false;
    }
    sf::Texture buff;

    if(!buff.loadFromImage(img, sf::IntRect(0,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::Star] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(16,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::LineVertical] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(32,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::LineHorizontal] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(48,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::BottomRightCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(64,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::BottomLeftCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(80,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::TopRightCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(96,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::TopLeftCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(112,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::RightHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(128,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::LeftHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(144,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::TopHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(160,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::BottomHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(176,0,16,16)))
    {
        g_Sprites.clear();
        return false;
    }
    g_Sprites[ESprite::LineCross] = buff;

    return true;
}
