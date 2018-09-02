#include "Game.hpp"

constexpr std::chrono::milliseconds Game::g_Tick;

using namespace std::chrono_literals;

void Game::start()
{    
    setup();
    m_InputThread = std::thread(&Game::processInputLoop, this);
    m_GameThread = std::thread(&Game::gameLoop, this);
}

void Game::shutDown()
{
    if (!isAboutToQuit())
        m_IsAboutToQuit = true;
    m_GameThread.join();
    m_InputThread.join();
}

void Game::processEvent(const sf::Keyboard::Key& AKey)
{
    std::lock_guard<std::mutex> lock(m_InputMutex);
    m_InputQueue.push(AKey);
}

void Game::gameLoop()
{
    while(!isAboutToQuit())
    {
        std::this_thread::sleep_for(g_Tick);
        if(!m_IsPaused && !m_IsGameOver)
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

void Game::processInputLoop()
{
    auto Handler = ControlHandler::getInstance();
    while(!isAboutToQuit())
    {
        std::lock_guard<std::mutex> lock(m_InputMutex);
        while(!m_InputQueue.empty())
        {
            sf::Keyboard::Key key = m_InputQueue.front();
            m_InputQueue.pop();

            if(key == Handler->getKey(ControlHandler::Action::Quit))
            {
                m_IsAboutToQuit = true;
                break;
            }
            if(key == Handler->getKey(ControlHandler::Action::Pause))
                m_IsPaused = !m_IsPaused;

            if(!isPaused())
            {
                if(key == Handler->getKey(ControlHandler::Action::Up))
                    m_Snake->turn(EDirection::Up);
                if(key == Handler->getKey(ControlHandler::Action::Down))
                    m_Snake->turn(EDirection::Down);
                if(key == Handler->getKey(ControlHandler::Action::Left))
                    m_Snake->turn(EDirection::Left);
                if(key == Handler->getKey(ControlHandler::Action::Right))
                    m_Snake->turn(EDirection::Right);
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

    newDrawable(m_Apple);
    newDrawable(m_Snake);
    newDrawable(m_Wall);
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
    auto next = m_Snake->aboutToMove();
    if(m_Snake->isHit(*m_Apple))
    {
        relocateApple();

        m_Score++;
        if(m_Score % 5 == 0)
            expandWall();
    }
    else
    {
        m_Snake->move();
        if(m_Snake->isHitSelf() || m_Wall->isHit(next))
        {
            newDrawable(std::make_unique<DeathSpot>(next));
            m_IsGameOver = true;
        }
    }
}

bool Game::isGameOver() const
{
    return m_IsGameOver;
}

bool Game::isPaused() const
{
    return m_IsPaused;
}

bool Game::isAboutToQuit() const
{
    return m_IsAboutToQuit;
}

uint16_t Game::getScore() const
{
    return m_Score;
}
