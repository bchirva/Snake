#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>
#include <functional>
#include <chrono>

#include "Window.hpp"
#include "Snake.hpp"
#include "Wall.hpp"
#include "Apple.hpp"

class Game
{
private:
    std::thread m_GraphicThread;
    std::thread m_InputThread;

    Window m_Window;

    std::shared_ptr<Snake> m_Snake;
    std::shared_ptr<Wall> m_Wall;
    std::shared_ptr<Apple> m_Apple;

    uint16_t m_Score = 0;
    bool m_IsRunning = true;
    bool m_IsPaused = false;

    void inputLoop();
public:
    Game() = default;
    ~Game() = default;

    int exec();
};

#endif
