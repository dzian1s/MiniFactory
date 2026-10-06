#include "GameScreen.h"
#include "Config.h"
#include "raylib.h"

void GameScreen::render() const
{ 
    BeginMode2D(camera);

    world.render(camera);
    player.render();

    EndMode2D();
}

Screen::Type GameScreen::update(float dt)
{
    player.update(dt, world);
    camera.target = player.getPosition();
    return Screen::Type::None;
}

GameScreen::GameScreen()
    :world(WORLD_CHUNKS_X, WORLD_CHUNKS_Y)
    ,player({
            WORLD_CHUNKS_X * CHUNK_SIZE * TILE_SIZE / 2.0f,
            WORLD_CHUNKS_Y * CHUNK_SIZE * TILE_SIZE / 2.0f
            })
            , camera()
{
    camera.target = player.getPosition();

    camera.offset = 
    {
        SCREEN_WIDTH / 2.0f,
        SCREEN_HEIGHT / 2.0f
    };

    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}
