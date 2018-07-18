#include "Game.hpp"

constexpr std::chrono::milliseconds Game::g_Tick;
bool Game::g_IsGameOver = false;
bool Game::g_IsPaused = false;
bool Game::g_IsAboutToQuit = false;
uint16_t Game::g_Score = 0;

using namespace std::chrono_literals;
int Game::exec()
{
    m_Window.redirectEvent = std::bind(&Game::receiveInput, this, std::placeholders::_1);

    m_GraphicThread = std::thread(&Window::drawLoop, &m_Window);
    m_InputThread = std::thread(&Game::processInputLoop, this); 

    play();

    m_InputThread.join();
    m_GraphicThread.join();
    
    return 1;
}

void Game::play()
{
    setup();
    while(!Game::isAboutToQuit())
    {
        std::this_thread::sleep_for(g_Tick);
        if(!g_IsPaused && !g_IsGameOver)
        {
            m_TickCount++;
            if(m_TickCount == 50)
            {
                step();
                m_TickCount = 0;
            }
        }
    }
}

void Game::receiveInput(sf::Keyboard::Key AKey)
{
    std::lock_guard<std::mutex> lock(m_InputMutex);
    m_InputQueue.push(AKey);
}

void Game::processInputLoop()
{
    while(!Game::isAboutToQuit())
    {
        std::lock_guard<std::mutex> lock(m_InputMutex);
        while(!m_InputQueue.empty())
        {
            sf::Keyboard::Key key = m_InputQueue.front();
            m_InputQueue.pop();
             
            if(key == (sf::Keyboard::Escape))
            {
                g_IsAboutToQuit = true;
                break; 
            }
            if( key == (sf::Keyboard::Pause) ||
                key == (sf::Keyboard::Space))
            {
                g_IsPaused = !g_IsPaused;
            }

            if(!Game::isPaused())
            {
                if( key == (sf::Keyboard::W) ||
                    key == (sf::Keyboard::Up) ||
                    key == (sf::Keyboard::Num8))
                {
                    m_Snake->turn(EDirection::Top);
                }
                if( key == (sf::Keyboard::S) ||
                    key == (sf::Keyboard::Down) ||
                    key == (sf::Keyboard::Num2))
                {
                    m_Snake->turn(EDirection::Bottom);
                }
                if( key == (sf::Keyboard::A) ||
                    key == (sf::Keyboard::Left) ||
                    key == (sf::Keyboard::Num4))
                {
                     m_Snake->turn(EDirection::Left);
                }
                if( key == (sf::Keyboard::D) ||
                    key == (sf::Keyboard::Right) ||
                    key == (sf::Keyboard::Num6))
                {
                    m_Snake->turn(EDirection::Right);
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

    relocateApple();

    m_Window.reset();
    m_Window.addDrawable(m_Apple);
    m_Window.addDrawable(m_Snake);
    m_Window.addDrawable(m_Wall);
}

void Game::relocateApple()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int8_t> range(0, FIELD_SIZE - 1);

    do
    {
        m_Apple->setCoord(range(gen), range(gen));
    }
    while(m_Snake->isHit(*m_Apple) || m_Wall->isHit(*m_Apple));
}

void Game::expandWall()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int8_t> range(0, FIELD_SIZE - 1);

    Line expandLine;
    do
    {
        Point start(range(gen), range(gen));
        EDirection dir = static_cast<EDirection>(range(gen) % 4);
        expandLine = Line(start, dir, 4);
    }
    while (expandLine.isHit(*m_Apple) || expandLine.isHit(*m_Snake) || expandLine.isHit(m_Snake->aboutToMove()));
    m_Wall->expand(expandLine);
}

void Game::step()
{
    Point next = m_Snake->aboutToMove();
    if(next.isHit(*m_Apple))
    {
        m_Snake->eat();
        g_Score++;

        relocateApple();
        if(g_Score % 5 == 0)
        {
            expandWall();
        }
    }
    else
    {
        if(m_Snake->isHit(next) || m_Snake->isHit(next))
        {
            m_Window.addDrawable(std::make_unique<DeathSpot>(next));
            g_IsGameOver = true;
        }

        m_Snake->move();
    }
}

bool Game::isGameOver()
{
    return g_IsGameOver;
}

bool Game::isPaused()
{
    return g_IsPaused;
}

bool Game::isAboutToQuit()
{
    return g_IsAboutToQuit;
}

uint16_t Game::getScore()
{
    return g_Score;
}
