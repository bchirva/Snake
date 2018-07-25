#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <memory>
#include <functional>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"
#include "Base.hpp"
#include "TextureLoader.hpp"

class Window
{
private:
    sf::RenderWindow m_Window;
    std::vector<std::shared_ptr<IDrawable>> m_Drawables;
    sf::Font m_Font;

    inline void drawGame();
    inline void showMenu();

public:
    Window();
    ~Window() = default;
    
    void addDrawable(const std::shared_ptr<IDrawable>& ADrawable);
    void drawLoop();

    std::function<void(sf::Keyboard::Key)> redirectEvent;
};

#endif
