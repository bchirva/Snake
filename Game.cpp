#include "Game.hpp"

int Game::exec()
{
    m_Apple = std::make_shared<Apple>();
    m_Window.addDrawable(m_Apple);
    //m_Window.addDrawable(m_Snake);
    //m_Window.addDrawable(m_Wall);

    m_GraphicThread = std::thread(std::bind(&Window::drawLoop, &m_Window));
    

    m_GraphicThread.join();
    return 1;
}

void Game::inputLoop()
{
    while(m_IsRunning)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // quit game
        }
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Pause) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // pause game
        }

        if(!m_IsPaused)
        {
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
                m_Snake->turn(EDirection::Top);
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
                m_Snake->turn(EDirection::Bottom);
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
                m_Snake->turn(EDirection::Left);
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
                m_Snake->turn(EDirection::Right);
        }
   }
}
