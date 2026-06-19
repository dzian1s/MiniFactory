#pragma once

#include <raylib.h>

class ScreenObject
{
public:
    ScreenObject(Rectangle rect, Color color);
    void render();
    void update(float dt);

private:
    Rectangle rect;
    Color color;
};
