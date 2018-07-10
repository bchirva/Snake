#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>
#include <functional>

#include "Window.hpp"
#include "Snake.hpp"
#include "Wall.hpp"
#include "Apple.hpp"

class Game
{
private:
    std::thread m_GraphicThread;
    Window m_Window;

    std::shared_ptr<Snake> m_Snake;
    std::shared_ptr<Wall> m_Wall;
    std::shared_ptr<Apple> m_Apple;
public:
    Game() = default;
    ~Game() = default;

    int exec();
};

#endif
