#pragma once

#include <memory>
#include <raylib.h>
#include "ScreenObject.h"
#include "World.h"

class Screen
{
public:
    Screen();
    void render();
    void update(float dt);
    void setScreenObject(Rectangle rect, Color color);

private:
    std::unique_ptr<ScreenObject> obj;
    World world;
};
