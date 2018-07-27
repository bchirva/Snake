cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Snake)

find_package(Threads REQUIRED)
find_package(SFML COMPONENTS system graphics window REQUIRED)

add_executable(Snake 
    main.cpp
    Game.cpp
    Window.cpp
    Snake.cpp
    Wall.cpp
    Line.cpp
    Apple.cpp
    Point.cpp
    TextureLoader.cpp
    DeathSpot.cpp
    )

set_property(TARGET Snake PROPERTY CXX_STANDARD 14)

if(NOT ${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()

if(MSVC)
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

if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
