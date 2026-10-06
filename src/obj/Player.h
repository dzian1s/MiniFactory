#pragma once

#include <raylib.h>
#include "world/World.h"

class Player 
{
public:
    Player(Vector2 position);

    void render() const;
    void update(float dt, const World& world);

    Vector2 getPosition() const;
    bool canMoveTo(Vector2 position, const World& world) const;

private:
    Vector2 curPosition;
    float speed = 300.0f;
};
