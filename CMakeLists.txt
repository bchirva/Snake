cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(Snake)

find_package(Threads REQUIRED)
find_package(SFML COMPONENTS system graphics window REQUIRED)

add_executable(Snake 
    )

set_property(TARGET Snake PROPERTY CXX_STANDARD 14)

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

