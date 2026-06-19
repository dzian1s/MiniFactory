#include "Game.h"
#include "Screen.h"
#include "raylib.h"
#include "Config.h"

void Game::Run()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mini Factory");

    SetTargetFPS(60);

    playScreen.reset(new Screen()); 
    playScreen->setScreenObject({100, 100, 50, 50}, RED);

    while (!WindowShouldClose())
    {
        auto dt = GetFrameTime();
        update(dt);
        render();
    }

    CloseWindow();
}

void Game::render()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    playScreen->render();
    EndDrawing();
}

void Game::update(float dt)
{
   playScreen->update(dt);
}
