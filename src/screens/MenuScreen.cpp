#include "MenuScreen.h"
#include "screens/Screen.h"
#include <raylib.h>


Screen::Type MenuScreen::update(float dt)
{
    if(IsKeyPressed(KEY_ENTER)) return Screen::Type::Game;

    return Screen::Type::Menu;
}

void MenuScreen::render() const
{
    DrawText("Mini Factory", 250, 200, 40, BLACK);
    DrawText("Press ENTER to start", 270, 280, 20, GRAY);
};
