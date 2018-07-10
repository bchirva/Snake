#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>
#include <functional>

#include "Snake.hpp"
#include "Window.hpp"

class Game
{
private:
    std::thread m_GraphicThread;
    Window m_Window;

    std::shared_ptr<Snake> m_Snake;
public:
    Game() = default;
    ~Game() = default;

    int exec();
};

#endif
