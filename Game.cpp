#include "Game.hpp"
#include <iostream>

int Game::exec()
{
    setup();
    
    m_Window.redirectEvent = std::bind(&Game::getInput, this, std::placeholders::_1);
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
             
            if(key == (sf::Keyboard::Escape))
            {
                std::cout << "QUIT\n";
                // quit game
            }
            if( key == (sf::Keyboard::Pause) ||
                key == (sf::Keyboard::Space))
            {
                std::cout << "PAUSE\n";
                // pause game
            }

            if(!m_IsPaused)
            {
                if( key == (sf::Keyboard::W) ||
                    key == (sf::Keyboard::Up) ||
                    key == (sf::Keyboard::Num8))
                {
                    std::cout << "TOP\n";
                    m_Snake->turn(EDirection::Top);
                }
                if( key == (sf::Keyboard::S) ||
                    key == (sf::Keyboard::Down) ||
                    key == (sf::Keyboard::Num2))
                {
                    m_Snake->turn(EDirection::Bottom);
                    std::cout << "BOTTOM\n";
                }
                if( key == (sf::Keyboard::A) ||
                    key == (sf::Keyboard::Left) ||
                    key == (sf::Keyboard::Num4))
                {
                     m_Snake->turn(EDirection::Left);
                     std::cout << "LEFT\n";
                }
                if( key == (sf::Keyboard::D) ||
                    key == (sf::Keyboard::Right) ||
                    key == (sf::Keyboard::Num6))
                {
                    m_Snake->turn(EDirection::Right);
                    std::cout << "RIGHT\n";
                }
            }
        }
    }
}

void Game::setup()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int8_t> range(0, FIELD_SIZE - 1);
    
    m_Apple = std::make_shared<Apple>();
    m_Wall = std::make_shared<Wall>();
    m_Snake = std::make_shared<Snake>(Point(range(gen), range(gen)), static_cast<EDirection>(range(gen) % 4));

    do
    {
        m_Apple->setCoord(range(gen), range(gen));
    } 
    while(m_Snake->isHit(*m_Apple));
}
