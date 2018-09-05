#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>
#include "TextureLoader.hpp"

class Scene
{
public:
    Scene() = default;
    ~Scene() = default;
    void show(sf::RenderWindow& ATargetWindow);

protected:
    virtual void processInput(sf::Keyboard::Key AKey) = 0;
    virtual void draw(sf::RenderWindow& ATargetWindow) const = 0;
};

#endif // SCENE_HPP
