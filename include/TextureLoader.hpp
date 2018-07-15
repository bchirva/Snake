#ifndef SPRITELOADER_HPP
#define SPRITELOADER_HPP

#include <SFML/Graphics.hpp>
#include <map>

enum class ESprite
{
    LineVertical,
    LineHorizontal,
    TopLeftCorner,
    TopRightCorner,
    BottomLeftCorner,
    BottomRightCorner,
    LineCross,
    Star,
    TopHalfCross,
    BottomHalfCross,
    LeftHalfCross,
    RightHalfCross
};

class TextureLoader
{
private:
    static std::map<ESprite, sf::Texture> g_Sprites;
public:
    TextureLoader() = delete;
    ~TextureLoader() = delete;

    static bool loadTextures();
    static const sf::Texture& getTexture(ESprite ARequestedSprite);
};

#endif
