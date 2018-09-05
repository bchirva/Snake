#include "Window.hpp"

Window::Window()
{
}

void Window::drawGame()
{
    Game game;
    game.start();
    game.show(m_Window);
    game.shutDown();
}

void Window::showRecords()
{

}

void Window::showSettingsMenu()
{

}

void Window::showMainMenu()
{
    sf::Text label;
    Menu MainMenu ({{"New Game", std::bind(&Window::drawGame, this)},
                   {"Settings", std::bind(&Window::showSettingsMenu, this)},
                   {"Records", std::bind(&Window::showRecords, this)},
                   {"Quit", [this](){m_Window.close();}}
                   });

    MainMenu.show(m_Window);
}

void Window::open()
{
    m_Window.create(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE * 16) + 24),
                    "Snake",
                    sf::Style::Titlebar | sf::Style::Close);
    showMainMenu();
}
