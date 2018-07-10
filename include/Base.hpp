#ifndef BASE_HPP
#define BASE_HPP

#include <stdint.h>

namespace Snake
{
    enum class EDirection
    {
        Top = 1,
        Bottom = 2,
        Left = 4,
        Right = 8
    };

    constexpr uint8_t FIELD_SIZE = 24;
}

#endif
