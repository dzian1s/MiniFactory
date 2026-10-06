#pragma once

#include <raylib.h>

class Player 
{
public:
    Player(Vector2 position);
    void render() const;
    void update(float dt);

private:
    Vector2 curPosition;
    float speed = 100.0f;
};
