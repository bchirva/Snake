#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>
#include <functional>
#include <chrono>
#include <queue>
#include <random>

#include "Window.hpp"
#include "Snake.hpp"
#include "Wall.hpp"
#include "Apple.hpp"

class Game
{
private:
    Window m_Window;
    std::shared_ptr<Snake> m_Snake;
    std::shared_ptr<Wall> m_Wall;
    std::shared_ptr<Apple> m_Apple;

    std::thread m_GraphicThread;
    std::thread m_InputThread;

    static uint16_t g_Score;
    static bool g_IsRunning;
    static bool g_IsPaused;

    std::queue<sf::Keyboard::Key> m_InputQueue;
    std::mutex m_InputMutex;

    void receiveInput(sf::Keyboard::Key AKey);
    void processInputLoop();

    inline void setup();
public:
    Game() = default;
    ~Game() = default;

    static bool isRunning();
    static bool isPaused();
    static uint16_t getScore();

    int exec();
};

#endif
