cmake_minimum_required (VERSION 3.5.2 FATAL_ERROR)

project (Snake)

find_package (Threads REQUIRED)

add_executable (Snake
    src/main.cpp
    src/ui/Window.cpp
    src/ui/Scene.cpp
    src/ui/Menu.cpp
    src/ui/NewRecordMenu.cpp
    src/game/Game.cpp
    src/game/Snake.cpp
    src/game/Wall.cpp
    src/game/Line.cpp
    src/game/Apple.cpp
    src/game/Point.cpp
    src/game/DeathSpot.cpp
    src/common/TextureLoader.cpp
    src/common/ControlHandler.cpp
    src/common/TopScoreHolder.cpp
    )

set_property (TARGET Snake PROPERTY CXX_STANDARD 14)

if (NOT ${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    file(COPY resources DESTINATION ${CMAKE_BINARY_DIR}/)
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
       ${CMAKE_CURRENT_SOURCE_DIR}/src/game
       ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
       ${CMAKE_CURRENT_SOURCE_DIR}/src/common
    )

set(SFML_USE_SYSTEM OFF CACHE BOOL "Use installed binary instead of build SFML from source")
if(${SFML_USE_SYSTEM})
    find_package(SFML 2.5.0 COMPONENTS system graphics window REQUIRED)
else()
    add_subdirectory(3rdparty/sfml/)
endif()

set(YAML_USE_SYSTEM OFF CACHE BOOL "Use installed binary instead of build yaml-cpp from source")
if(${YAML_USE_SYSTEM})
    find_package(yaml-cpp REQUIRED)
else()
    add_subdirectory(3rdparty/yamlcpp/) 
endif()

target_link_libraries (Snake
    PRIVATE
        sfml-system
        sfml-graphics
        sfml-window
        yaml-cpp
        Threads::Threads
    )

if (CMAKE_GENERATOR STREQUAL "Unix Makefiles")
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()
