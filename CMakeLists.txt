cmake_minimum_required (VERSION 3.5.2 FATAL_ERROR)

project (Snake)

find_package (Threads REQUIRED)
find_package (SFML COMPONENTS system graphics window REQUIRED)

add_executable (Snake
    src/main.cpp
    src/ui/Window.cpp
    src/ui/Menu.cpp
    src/game/Game.cpp
    src/game/Snake.cpp
    src/game/Wall.cpp
    src/game/Line.cpp
    src/game/Apple.cpp
    src/game/Point.cpp
    src/game/DeathSpot.cpp
    src/common/TextureLoader.cpp
    src/common/ControlHandler.cpp
    src/common/FileDataAgent.cpp
    )

set_property (TARGET Snake PROPERTY CXX_STANDARD 14)

if (NOT ${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()

if (MSVC)
    target_compile_options(Snake PRIVATE /W4)
else()
    target_compile_options(Snake
        PRIVATE
            -Werror
            -Wall
            -Wextra
            -Wpedantic
        )
endif()

target_include_directories (Snake
    PRIVATE
       ${CMAKE_CURRENT_SOURCE_DIR}/include/game
       ${CMAKE_CURRENT_SOURCE_DIR}/include/ui
       ${CMAKE_CURRENT_SOURCE_DIR}/include/common
    )

target_link_libraries (Snake
    PRIVATE
        sfml-system
        sfml-graphics
        sfml-window
        Threads::Threads
    )

if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
