cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Snake)

find_package(Threads REQUIRED)
find_package(SFML COMPONENTS system graphics window REQUIRED)

add_executable(Snake 
    main.cpp
    Game.cpp
    Snake.cpp
    Line.cpp
    Point.cpp
    Window.cpp
    )

set_property(TARGET Snake PROPERTY CXX_STANDARD 14)

target_compile_options(Snake
    PRIVATE
        -Werror
        -Wall
        -Wextra
        -Wpedantic
    )

target_include_directories(Snake 
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

target_link_libraries(Snake
    PRIVATE
        sfml-system
        sfml-graphics
        sfml-window
        Threads::Threads
    )

