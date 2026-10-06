#include "Player.h"
#include "Config.h"
#include "world/Cell.h"
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

void Player::update(float dt, const World& world)
{
    Vector2 movement ={0.0f, 0.0f};

    if (IsKeyDown(KEY_W)) movement.y -= speed * dt;
    if (IsKeyDown(KEY_S)) movement.y += speed * dt;
    if (IsKeyDown(KEY_A)) movement.x -= speed * dt;
    if (IsKeyDown(KEY_D)) movement.x += speed * dt;

    Vector2 nextPosition = curPosition;

    nextPosition.x += movement.x;
    if (canMoveTo(nextPosition, world)) curPosition.x = nextPosition.x;
    nextPosition = curPosition;
    nextPosition.y += movement.y;
    if (canMoveTo(nextPosition, world)) curPosition.y = nextPosition.y;
}

Vector2 Player::getPosition() const
{
    return curPosition;    
}

bool Player::canMoveTo(Vector2 position, const World& world) const
{
    const float left = position.x;
    const float right = position.x + PLAYER_SIZE - 1.0f;
    const float top = position.y;
    const float bottom = position.y + PLAYER_SIZE - 1.0f;

    const GridPosition topLeft = 
    {
        static_cast<int>(left) / TILE_SIZE,
        static_cast<int>(top) / TILE_SIZE
    };

    const GridPosition topRight = 
    {
        static_cast<int>(right) / TILE_SIZE,
        static_cast<int>(top) / TILE_SIZE
    };

    const GridPosition bottomLeft = 
    {
        static_cast<int>(left) / TILE_SIZE,
        static_cast<int>(bottom) / TILE_SIZE
    };

    const GridPosition bottomRight = 
    {
        static_cast<int>(right) / TILE_SIZE,
        static_cast<int>(bottom) / TILE_SIZE
    };

    return world.isWalkable(topLeft) &&
        world.isWalkable(topRight) &&
        world.isWalkable(bottomLeft) &&
        world.isWalkable(bottomRight);
}
