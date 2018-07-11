#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include <Drawable.hpp>
#include <Base.hpp>
#include <SpriteLoader.hpp>

class Window
{
private:
    sf::RenderWindow m_Window;
    std::vector<std::shared_ptr<IDrawable>> m_Drawables;
public:
    Window();
    ~Window() = default;
    
    void addDrawable(const std::shared_ptr<IDrawable>& ADrawable);
    void drawLoop();
};

#endif
