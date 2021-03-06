#ifndef SPRITELOADER_HPP
#define SPRITELOADER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include <mutex>

extern std::string AppLocation;

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
public:
    static std::shared_ptr<TextureLoader> getInstance();

    const sf::Texture& getTexture(ESprite ARequestedSprite) const;
    const sf::Font& getFont() const;

private:
    static std::shared_ptr<TextureLoader> g_Instance;
    static std::mutex g_InstanceMutex;

    std::map<ESprite, sf::Texture> m_Sprites {};
    sf::Font m_Font;

    TextureLoader() = default;
    bool loadTextures();
    bool loadFont();
};

#endif
