#include "Game.hpp"
#include <iostream>

int Game::exec()
{
    setup();
    
    m_Window.addDrawable(m_Apple);
    m_Window.addDrawable(m_Snake);
    //m_Window.addDrawable(m_Wall);

    m_GraphicThread = std::thread(std::bind(&Window::drawLoop, &m_Window));
    m_InputThread = std::thread(std::bind(&Game::processInputLoop, this)); 
    
    m_InputThread.join();
    m_GraphicThread.join();
    
    return 1;
}

void Game::getInput(sf::Keyboard::Key AKey)
{
    std::lock_guard<std::mutex> lock(m_InputMutex);
    m_InputQueue.push(AKey);
}

void Game::processInputLoop()
{
    while(m_IsRunning)
    {
        std::lock_guard<std::mutex> lock(m_InputMutex);
        while(!m_InputQueue.empty())
        {
            sf::Keyboard::Key key = m_InputQueue.front();
            m_InputQueue.pop();
    
            

        }
/*        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            std::cout << "QUIT\n";
            // quit game
        }
        if( sf::Keyboard::isKeyPressed(sf::Keyboard::Pause) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            std::cout << "PAUSE\n";
            // pause game
        }

        if(!m_IsPaused)
        {
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
            {
                std::cout << "TOP\n";
                m_Snake->turn(EDirection::Top);
            }
            if( sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                m_Snake->turn(EDirection::Bottom);
                std::cout << "BOTTOM\n";
            }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
             {
                 m_Snake->turn(EDirection::Left);
                 std::cout << "LEFT\n";
             }
             if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
             {
                 m_Snake->turn(EDirection::Right);
                 std::cout << "RIGHT\n";
            }
        }
*/    }
}
