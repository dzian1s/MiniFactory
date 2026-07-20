#pragma once

#include <memory>
#include <raylib.h>
#include "obj/ScreenObject.h"
#include "world/World.h"
#include "Screen.h"

class GameScreen : public Screen
{
public:
    GameScreen();

    Screen::Type update(float dt) override;
    void render() const override;
    void setScreenObject(Rectangle rect, Color color);

private:
    std::unique_ptr<ScreenObject> obj;
    World world;
};
