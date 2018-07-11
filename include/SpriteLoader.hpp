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

class SpriteLoader
{
private:
    static std::map<ESprite, sf::Texture> g_Sprites;
public:
    SpriteLoader() = delete;
    ~SpriteLoader() = delete;

    static void loadSprites();
    static sf::Texture getSprite(ESprite ARequestedSprite);
};

#endif
