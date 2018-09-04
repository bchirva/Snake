#include "Window.hpp"

Window::Window()
{
}

void Window::addDrawable(const std::shared_ptr<IDrawable>& ADrawable)
{
    m_Drawables.push_back(ADrawable);
}

void Window::drawGame()
{
    Game game;
    game.newDrawable = std::bind(&Window::addDrawable, this, std::placeholders::_1);
    game.start();

    while(!game.isAboutToQuit())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            //if (event.type == sf::Event::Closed) break;
            if (event.type == sf::Event::KeyPressed)
                game.processEvent(event.key.code);
        }

        sf::RectangleShape field(sf::Vector2f(FIELD_SIZE * 16, FIELD_SIZE * 16));
        field.setFillColor(sf::Color(160, 160, 0));
        sf::RectangleShape footer(sf::Vector2f(FIELD_SIZE * 16, 24));
        footer.setFillColor(sf::Color(32, 32, 32));
        footer.setPosition(0, FIELD_SIZE * 16);

        sf::Text scoreLabel;
        scoreLabel.setFont(TextureLoader::getInstance()->getFont());
        scoreLabel.setPosition(8, FIELD_SIZE * 16 + 4);
        scoreLabel.setCharacterSize(16);
        scoreLabel.setFillColor(sf::Color(224, 224, 224));

        sf::Text stateLabel;
        stateLabel.setFont(TextureLoader::getInstance()->getFont());
        stateLabel.setCharacterSize(16);
        stateLabel.setFillColor(sf::Color::Red);

        std::string currentScore = std::to_string(game.getScore());
        scoreLabel.setString("Score: " + currentScore);

        if(game.isPaused())
            stateLabel.setString("PAUSED");
        if(game.isGameOver())
            stateLabel.setString("GAME OVER");

        m_Window.draw(field);
        m_Window.draw(footer);

        m_Window.draw(scoreLabel);
        if(!stateLabel.getString().isEmpty())
        {
            stateLabel.setPosition((FIELD_SIZE * 16 / 2) - stateLabel.getGlobalBounds().width / 2 , FIELD_SIZE * 16 + 4);
            m_Window.draw(stateLabel);
        }

        for(auto Drawable: m_Drawables)
            Drawable->draw(m_Window);
        m_Window.display();
    }

    game.shutDown();
    m_Drawables.clear();
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

    sf::RectangleShape field(sf::Vector2f(FIELD_SIZE * 16, FIELD_SIZE * 16));
    field.setFillColor(sf::Color(160, 160, 0));
    sf::RectangleShape footer(sf::Vector2f(FIELD_SIZE * 16, 24));
    footer.setFillColor(sf::Color(32, 32, 32));
    footer.setPosition(0, FIELD_SIZE * 16);

    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            //if (event.type == sf::Event::Closed) break;
            if (event.type == sf::Event::KeyPressed)
                MainMenu.processEvent(event.key.code);
        }

        m_Window.clear();
        m_Window.draw(field);
        m_Window.draw(footer);
        MainMenu.draw(m_Window);
        m_Window.display();
    }
}

void Window::open()
{
    m_Window.create(sf::VideoMode(FIELD_SIZE * 16, (FIELD_SIZE * 16) + 24),
                    "Snake",
                    sf::Style::Titlebar | sf::Style::Close);
    showMainMenu();
}
