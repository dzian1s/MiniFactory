#include "GameScreen.h"
#include "Config.h"
#include "raylib.h"

void GameScreen::render() const
{ 
    world.render();
    player.render();
}

Screen::Type GameScreen::update(float dt)
{
    player.update(dt);
    return Screen::Type::None;
}

GameScreen::GameScreen()
    :world(WORLD_WIDTH, WORLD_HEIGHT)
    ,player({100.0f, 100.0f})
{
}
