cmake_minimum_required(VERSION 3.26)
project(Hexxagon)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(SFML)



set(CMAKE_CXX_STANDARD 20)

add_executable(Hexxagon main.cpp
        game/main/GameEngine.cpp
        game/main/GameEngine.h
        game/gamestates/Playing.cpp
        game/gamestates/Playing.h
        game/gamestates/Menu.cpp
        game/gamestates/Menu.h
        game/main/enums.cpp
        game/Entities/Player.cpp
        game/Entities/Player.h
        game/Entities/AIComputerPlayer.cpp
        game/Entities/AIComputerPlayer.h
        game/Entities/Hexagon.cpp
        game/Entities/Hexagon.h)

target_link_libraries(
        Hexxagon
        sfml-graphics
)