#include "Window.hpp"
#include <Game.hpp>

Window::Window()
    : m_Window(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE + 1) * 16), "Snake", sf::Style::Titlebar | sf::Style::Close)
{
    m_Window.setActive(false);
    SpriteLoader::loadSprites();
}

void Window::addDrawable(const std::shared_ptr<IDrawable>& ADrawable)
{
    m_Drawables.push_back(ADrawable);
}

void Window::drawLoop()
{
    m_Window.setFramerateLimit(60); 
    m_Window.setActive(true);

    while(m_Window.isOpen())
    {
        if(Game::isRunning())
        {
            sf::Event event;
            while (m_Window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    redirectEvent(sf::Keyboard::Escape);
                if (event.type == sf::Event::KeyPressed)
                    redirectEvent(event.key.code);
            }

            m_Window.clear();
            for(auto Drawable: m_Drawables)
                Drawable->draw(m_Window);
            m_Window.display();
        }
        else
        {
            m_Window.close();
        }
    }
}

