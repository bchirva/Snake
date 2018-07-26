#include "Window.hpp"
#include "Game.hpp"

#include <iostream>

const std::map<Window::EMenuItem, std::string> Window::g_MenuItems = {
    {Window::EMenuItem::NewGame, "New Game"},
    {Window::EMenuItem::Options, "Options"},
    {Window::EMenuItem::Records, "Records"},
    {Window::EMenuItem::Quit,    "Quit"}
};

Window::Window()
{
    m_CurrentMenuItem = EMenuItem::NewGame;
    TextureLoader::loadTextures();
    m_Font.loadFromFile("./resources/font/VeraMono.ttf");
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
        if(!Game::isAboutToQuit())
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
            drawGame();

        }
        else
        {
            m_Window.close();
        }
    }
}

void Window::drawGame()
{
    sf::RectangleShape field(sf::Vector2f(FIELD_SIZE * 16, FIELD_SIZE * 16));
    field.setFillColor(sf::Color(160, 160, 0));
    sf::RectangleShape footer(sf::Vector2f(FIELD_SIZE * 16, 24));
    footer.setFillColor(sf::Color(32, 32, 32));
    footer.setPosition(0, FIELD_SIZE * 16);
    
    sf::Text scoreLabel;
    scoreLabel.setFont(m_Font);
    scoreLabel.setPosition(8, FIELD_SIZE * 16 + 4);
    scoreLabel.setCharacterSize(16);
    scoreLabel.setFillColor(sf::Color(224, 224, 224));

    sf::Text stateLabel;
    stateLabel.setFont(m_Font);
    stateLabel.setCharacterSize(16);
    stateLabel.setFillColor(sf::Color::Red);

    std::string currentScore = std::to_string(Game::getScore());
    scoreLabel.setString("Score: " + currentScore);
    
    if(Game::isPaused())
    {
        stateLabel.setString("PAUSED");
        stateLabel.setPosition((FIELD_SIZE * 16 / 2) - stateLabel.getGlobalBounds().width / 2 , FIELD_SIZE * 16 + 4);
    }
    
    m_Window.draw(field);
    m_Window.draw(footer);
    
    m_Window.draw(scoreLabel);
    m_Window.draw(stateLabel);
    for(auto Drawable: m_Drawables)
        Drawable->draw(m_Window);
    m_Window.display();

}

void Window::showMenu()
{
    sf::Text label;
    label.setFont(m_Font);
    label.setCharacterSize(24);
    sf::RectangleShape active;
    active.setFillColor(sf::Color::Green);
    active.setOutlineThickness(2.0);
    active.setOutlineColor(sf::Color::Black);

    sf::RectangleShape field(sf::Vector2f(m_Window.getSize().x, m_Window.getSize().y));
    field.setFillColor(sf::Color(160, 160, 0));
    
    while(m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_Window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    switch (m_CurrentMenuItem)
                    {
                        case EMenuItem::NewGame: m_CurrentMenuItem = EMenuItem::Quit;       break;
                        case EMenuItem::Options: m_CurrentMenuItem = EMenuItem::NewGame;    break;
                        case EMenuItem::Records: m_CurrentMenuItem = EMenuItem::Options;    break;
                        case EMenuItem::Quit:    m_CurrentMenuItem = EMenuItem::Records;    break;
                        default: break;
                    }
                    break;
                case sf::Keyboard::Down:
                    switch (m_CurrentMenuItem)
                    {
                        case EMenuItem::NewGame: m_CurrentMenuItem = EMenuItem::Options;    break;
                        case EMenuItem::Options: m_CurrentMenuItem = EMenuItem::Records;    break;
                        case EMenuItem::Records: m_CurrentMenuItem = EMenuItem::Quit;       break;
                        case EMenuItem::Quit:    m_CurrentMenuItem = EMenuItem::NewGame;    break;
                        default: break;
                    }
                    break;
                case sf::Keyboard::Escape:
                    m_Window.close();
                    break;
                case sf::Keyboard::Enter:
                    switch(m_CurrentMenuItem)
                    {
                        case EMenuItem::NewGame:
                            break;
                        case EMenuItem::Options: 
                            break;
                        case EMenuItem::Records: 
                            break;
                        case EMenuItem::Quit:
                            m_Window.close();
                            break;
                        default: break;
                    }
                default: break;
                }
            }
        }

        int top = (m_Window.getSize().y - 136) / 2;
        
        m_Window.clear();
        m_Window.draw(field);
        for(auto item: g_MenuItems)
        {        
            label.setFillColor(sf::Color::Green);
            label.setString(item.second);
            label.setPosition((m_Window.getSize().x - label.getLocalBounds().width) / 2, top);
            if(m_CurrentMenuItem == item.first)
            {
                active.setPosition(label.getPosition());
                active.move(-8.0, .0);
                active.setSize(sf::Vector2f(label.getLocalBounds().width + 16, label.getLocalBounds().height + 8));
                m_Window.draw(active);
                label.setFillColor(sf::Color::Black);
            }
            m_Window.draw(label);
            top += 40;
        }
        m_Window.display();
    }
}

void Window::open()
{
    m_Window.create(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE * 16) + 24), "Snake", sf::Style::Titlebar | sf::Style::Close);
    showMenu();
}
