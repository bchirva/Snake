#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Drawable.hpp"
#include "Base.hpp"
#include "TextureLoader.hpp"
#include "ControlHandler.hpp"
#include "Menu.hpp"

class Window
{
private:
    sf::RenderWindow m_Window;

    void drawGame();
    void showRecords();
    void showSettingsMenu();
    void showMainMenu();

public:
    Window();
    ~Window() = default;
    
    void open();
};

#endif
