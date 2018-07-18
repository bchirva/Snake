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
#include "DeathSpot.hpp"

class Game
{
private:
    Window m_Window;
    std::shared_ptr<Snake> m_Snake = nullptr;
    std::shared_ptr<Wall> m_Wall = nullptr;
    std::shared_ptr<Apple> m_Apple = nullptr;

    std::thread m_GraphicThread;
    std::thread m_InputThread;

    static uint16_t g_Score;
    static bool g_IsGameOver;
    static bool g_IsPaused;
    static bool g_IsAboutToQuit;

    uint8_t m_TickCount = 0;
    static constexpr std::chrono::milliseconds g_Tick {10};

    std::queue<sf::Keyboard::Key> m_InputQueue;
    std::mutex m_InputMutex;

    void receiveInput(sf::Keyboard::Key AKey);
    void processInputLoop();


    void play();

    inline void setup();
    inline void step();
    inline void relocateApple();
    inline void expandWall();

public:
    Game() = default;
    ~Game() = default;

    static bool isGameOver();
    static bool isPaused();
    static bool isAboutToQuit();
    static uint16_t getScore();

    int exec();
};

#endif
