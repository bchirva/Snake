#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Drawable.hpp"
#include "Base.hpp"
#include "TextureLoader.hpp"

class Window
{
private:
    enum class EMenuItem
    {
        NewGame,
        Options,
        Records,
        Quit
    };

    static const std::map<EMenuItem, std::string> g_MenuItems; 
    EMenuItem m_CurrentMenuItem;

    sf::RenderWindow m_Window;
    sf::Font m_Font;

    std::vector<std::shared_ptr<IDrawable>> m_Drawables;
    void addDrawable(const std::shared_ptr<IDrawable>& ADrawable);

    void drawGame();
    void showMenu();

public:
    Window();
    ~Window() = default;
    
    void open();
};

#endif
