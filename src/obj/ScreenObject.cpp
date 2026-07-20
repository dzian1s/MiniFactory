#include "ScreenObject.h"

ScreenObject::ScreenObject(Rectangle rect, Color color)
    : rect(rect)
    , color(color)
{}

void ScreenObject::render() 
{
    DrawRectangleRec(rect, color);
}

void ScreenObject::update(float dt)
{
    rect.x += 10 * dt;
}
