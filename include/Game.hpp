#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <thread>

#include "Snake.hpp"

class Game
{
public:
    Game() = default;
    ~Game() = default;

    int exec();
};

#endif
