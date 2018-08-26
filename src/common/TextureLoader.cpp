#include "TextureLoader.hpp"
#include <iostream>

std::shared_ptr<TextureLoader> TextureLoader::g_Instance = nullptr;
std::mutex TextureLoader::g_InstanceMutex;

const sf::Texture& TextureLoader::getTexture(ESprite ARequestedSprite) const
{
    auto it = m_Sprites.find(ARequestedSprite);
    return it->second;
}

const sf::Font &TextureLoader::getFont() const
{
    return m_Font;
}

std::shared_ptr<TextureLoader> TextureLoader::getInstance()
{
    if(!g_Instance)
    {
        std::lock_guard<std::mutex> lock(g_InstanceMutex);
        if(!g_Instance)
        {
            g_Instance.reset(new TextureLoader());
            g_Instance->loadTextures();
            g_Instance->loadFont();
        }
    }
    return g_Instance;
}

bool TextureLoader::loadTextures()
{
    sf::Image img;
    if(!img.loadFromFile("./resources/img/sprite_sheet.png"))
    {
        m_Sprites.clear();
        return false;
    }
    sf::Texture buff;

    if(!buff.loadFromImage(img, sf::IntRect(0,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::Star] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(16,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::LineVertical] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(32,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::LineHorizontal] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(48,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::BottomRightCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(64,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::BottomLeftCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(80,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::TopRightCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(96,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::TopLeftCorner] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(112,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::RightHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(128,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::LeftHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(144,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::TopHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(160,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::BottomHalfCross] = buff;

    if(!buff.loadFromImage(img, sf::IntRect(176,0,16,16)))
    {
        m_Sprites.clear();
        return false;
    }
    m_Sprites[ESprite::LineCross] = buff;

    return true;
}

bool TextureLoader::loadFont()
{
    return m_Font.loadFromFile("./resources/font/VeraMono.ttf");
}
