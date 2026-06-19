#include "Screen.h"
#include "Config.h"
#include "raylib.h"
#include <memory>

void Screen::render()
{ 
    DrawText("Mini Factory", 300, 280, 30, DARKGRAY);
    if (obj != nullptr)
    {
        obj->render();
    }
    world.render();
}

void Screen::setScreenObject(Rectangle rect, Color color)
{
    obj = std::make_unique<ScreenObject>(rect, color);
}

void Screen::update(float dt)
{
    if (obj != nullptr) obj->update(dt);
}

Screen::Screen()
    :world(WORLD_WIDTH, WORLD_HEIGHT)
{
}


