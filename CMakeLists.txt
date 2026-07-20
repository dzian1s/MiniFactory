cmake_minimum_required(VERSION 3.20)

project(MiniFactory)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MiniFactory
    src/main.cpp
    src/app/Game.cpp
    src/screens/GameScreen.cpp
    src/screens/MenuScreen.cpp
    src/obj/ScreenObject.cpp
    src/world/World.cpp
)

target_link_libraries(MiniFactory PRIVATE raylib)

target_include_directories(MiniFactory PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
