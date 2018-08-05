#include "Window.hpp"

const std::map<Window::EMenuItem, std::string> Window::g_MenuItems = {
    {Window::EMenuItem::NewGame, "New Game"},
    {Window::EMenuItem::Settings, "Settings"},
    {Window::EMenuItem::Records, "Records"},
    {Window::EMenuItem::Quit,    "Quit"}
};

Window::Window()
{
    m_CurrentMenuItem = EMenuItem::NewGame;
    TextureLoader::loadTextures();
    ControlHandler::loadKeyMap();
    m_Font.loadFromFile("./resources/font/VeraMono.ttf");
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
            if (event.type == sf::Event::KeyPressed)
                game.receiveInput(event.key.code);
            else if (event.type == sf::Event::Closed)
                game.receiveInput(ControlHandler::getPrimaryKey(ControlHandler::Action::Quit));
        }

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
            {
                m_Window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                {
                    int8_t pickItem = static_cast<int8_t>(m_CurrentMenuItem) - 1;
                    if(pickItem < 0) pickItem = 3;
                    m_CurrentMenuItem = static_cast<EMenuItem>(pickItem);
                    break;
                }
                case sf::Keyboard::Down:
                {
                    int8_t pickItem = static_cast<int8_t>(m_CurrentMenuItem) + 1;
                    if(pickItem > 3) pickItem = 0;
                    m_CurrentMenuItem = static_cast<EMenuItem>(pickItem);
                    break;
                }
                case sf::Keyboard::Escape:
                    m_Window.close();
                    break;
                case sf::Keyboard::Enter:
                    switch(m_CurrentMenuItem)
                    {
                        case EMenuItem::NewGame:
                            drawGame();
                            break;
                        case EMenuItem::Settings:
                            showSettingsMenu();
                            break;
                        case EMenuItem::Records: 
                            showRecords();
                            break;
                        case EMenuItem::Quit:
                            m_Window.close();
                            break;
                    }
                    break;
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
    showMainMenu();
}
