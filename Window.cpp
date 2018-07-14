#include "Window.hpp"
#include <Game.hpp>

Window::Window()
    : m_Window(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE * 16) + 24), "Snake", sf::Style::Titlebar | sf::Style::Close)
{
    m_Window.setActive(false);
    SpriteLoader::loadSprites();
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

            std::string currentScore = std::to_string(Game::getScore());
            scoreLabel.setString("Score: " + currentScore);

            m_Window.draw(field);
            m_Window.draw(footer);
            
            m_Window.draw(scoreLabel);
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

