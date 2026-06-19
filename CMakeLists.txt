cmake_minimum_required(VERSION 3.20)

project(MiniFactory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MiniFactory
    src/main.cpp
    src/Game.cpp
    src/Screen.cpp
    src/ScreenObject.cpp
    src/World.cpp
)

target_link_libraries(MiniFactory PRIVATE raylib)
