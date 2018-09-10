#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>
#include "TextureLoader.hpp"

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;
    void show(sf::RenderWindow& ATargetWindow);
    void quit();

protected:
    bool m_IsActive = true;
    virtual void processInput(sf::Keyboard::Key AKey) = 0;
    virtual void draw(sf::RenderWindow& ATargetWindow) const = 0;
};

#endif // SCENE_HPP
