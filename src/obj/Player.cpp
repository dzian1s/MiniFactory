#include "Player.h"
#include <raylib.h>

Player::Player(Vector2 curPosition)
    : curPosition(curPosition)
   
{}

void Player::render() const
{
    DrawRectangle(static_cast<int>(curPosition.x)
                , static_cast<int>(curPosition.y)
                , 24
                , 24
                , RED);
}

void Player::update(float dt)
{
    if (IsKeyDown(KEY_W)) curPosition.y -= speed * dt;
    if (IsKeyDown(KEY_S)) curPosition.y += speed * dt;
    if (IsKeyDown(KEY_A)) curPosition.x -= speed * dt;
    if (IsKeyDown(KEY_D)) curPosition.x += speed * dt;
}
