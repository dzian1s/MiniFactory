#include "GameScreen.h"
#include "Config.h"
#include "raylib.h"
#include <memory>

void GameScreen::render() const
{ 
    DrawText("Mini Factory", 300, 280, 30, DARKGRAY);
    if (obj != nullptr)
    {
        obj->render();
    }
    world.render();
}

void GameScreen::setScreenObject(Rectangle rect, Color color)
{
    obj = std::make_unique<ScreenObject>(rect, color);
}

Screen::Type GameScreen::update(float dt)
{
    if (obj != nullptr) obj->update(dt);

    return Screen::Type::None;
}

GameScreen::GameScreen()
    :world(WORLD_WIDTH, WORLD_HEIGHT)
{
}
