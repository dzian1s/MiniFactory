#include "app/Game.h"
#include "screens/GameScreen.h"
#include "screens/MenuScreen.h"
#include "raylib.h"
#include "Config.h"
#include "screens/Screen.h"
#include <memory>

void Game::Run()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Mini Factory");
    SetExitKey(KEY_CAPS_LOCK);
    SetTargetFPS(60);

    currentScreen = std::make_unique<MenuScreen>();

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
    currentScreen->render();
    EndDrawing();
}

void Game::update(float dt)
{
   const Screen::Type requestedType = currentScreen->update(dt);

   if (requestedType == Screen::Type::Game)
       currentScreen = std::make_unique<GameScreen>();
   if (IsKeyPressed(KEY_ESCAPE))
       currentScreen = std::make_unique<MenuScreen>();

}
