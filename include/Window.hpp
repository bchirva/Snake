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

    sf::RenderWindow m_Window;
    sf::Font m_Font;
    
    EMenuItem m_CurrentMenuItem;
    std::vector<std::shared_ptr<IDrawable>> m_Drawables;

    inline void drawGame();
    inline void showMenu();

public:
    Window();
    ~Window() = default;
    
    void open();    
    void addDrawable(const std::shared_ptr<IDrawable>& ADrawable);
    void reset();
    void drawLoop();

    std::function<void(sf::Keyboard::Key)> redirectEvent;
};

#endif
