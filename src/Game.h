#pragma once
#include <memory>
#include "Screen.h"

class Screen;

class Game
{
public:
    void Run();

private:
    void render();
    void update(float dt);

private:
    std::unique_ptr<Screen> playScreen;
};
