#include "Window.hpp"
#include <iostream>

Window::Window()
    : m_Window(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE + 1) * 16), "Snake")
{
    m_Window.setFramerateLimit(60); 
}

void Window::addDrawable(const std::shared_ptr<IDrawable>& ADrawable)
{
    m_Drawables.push_back(ADrawable);
}

void Window::drawLoop()
{
    m_Window.setActive(true);
    while(m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
        }

        m_Window.clear();
        for(auto Drawable: m_Drawables)
            Drawable->draw(m_Window);
        m_Window.display();
    }
}
