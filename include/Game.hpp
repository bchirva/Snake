#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>
#include <functional>
#include <chrono>
#include <queue>
#include <random>

#include "Snake.hpp"
#include "Wall.hpp"
#include "Apple.hpp"
#include "DeathSpot.hpp"

class Game
{
private:
    std::shared_ptr<Snake> m_Snake = nullptr;
    std::shared_ptr<Wall> m_Wall = nullptr;
    std::shared_ptr<Apple> m_Apple = nullptr;

    uint16_t m_Score = 0;

    bool m_IsGameOver = false;
    bool m_IsPaused = false;
    bool m_IsAboutToQuit = false;

    uint8_t m_TickCount = 0;
    static constexpr std::chrono::milliseconds g_Tick {10};

    std::queue<sf::Keyboard::Key> m_InputQueue;
    std::thread m_InputThread;
    std::mutex m_InputMutex;

    void receiveInput(sf::Keyboard::Key AKey);
    void processInputLoop();

    inline void setup();
    inline void step();
    inline void relocateApple();
    inline void expandWall();

public:
    Game() = default;
    ~Game() = default;

    bool isGameOver();
    bool isPaused();
    bool isAboutToQuit();
    uint16_t getScore();

    void play();
    std::function<void(std::shared_ptr<IDrawable>)> newDrawable;
};

#endif
