#pragma once

#include <raylib.h>
#include "obj/Player.h"
#include "world/World.h"
#include "Screen.h"

class GameScreen : public Screen
{
public:
    GameScreen();

    Screen::Type update(float dt) override;
    void render() const override;
    
private:
    Player player;
    World world;
};
