#include "World.h"
#include "Cell.h"
#include "Config.h"
#include "world/Chunk.h"
#include <raylib.h>

World::World(int widthInChunks, int heightInChunks)
    : widthInChunks(widthInChunks)
    , heightInChunks(heightInChunks)
{
    chunks.reserve(widthInChunks * heightInChunks);

    for(int y = 0; y < heightInChunks; ++y)
    {
        for(int x = 0; x < widthInChunks; ++x)
        {
            chunks.emplace_back(x, y);
        }
    }
}

void World::update(float dt)
{
}

void World::render(const Camera2D& camera) const
{
    for (const Chunk& chunk : chunks)
    {
        chunk.render();
    }

    const auto mousePos = GetMousePosition();
    const auto hoveredCell = screenToGrid(mousePos, camera);

    if (isInside(hoveredCell))
    {
        const int screenX = hoveredCell.x * TILE_SIZE;
        const int screenY = hoveredCell.y * TILE_SIZE;

        Rectangle highlightedCell =
        {
            static_cast<float>(screenX),
            static_cast<float>(screenY),
            static_cast<float>(TILE_SIZE),
            static_cast<float>(TILE_SIZE)
        };

        DrawRectangleLinesEx(highlightedCell, 3.0f, BLACK);
    }
}

GridPosition World::screenToGrid(Vector2 screenPos, const Camera2D& camera) const
{
    const Vector2 worldPos = GetScreenToWorld2D(screenPos, camera);
    return 
    {
        static_cast<int>(worldPos.x)/TILE_SIZE,
        static_cast<int>(worldPos.y)/TILE_SIZE
    };
}

bool World::isInside(GridPosition position) const
{
    return position.x >= 0 &&
           position.y >= 0 &&
           position.x < widthInChunks * CHUNK_SIZE &&
           position.y < heightInChunks * CHUNK_SIZE;
}

Cell* World::tryGetCell(GridPosition position)
{
    if (!isInside(position))
        return nullptr;

    const int chunkX = position.x / CHUNK_SIZE;
    const int chunkY = position.y / CHUNK_SIZE;

    const int localX = position.x % CHUNK_SIZE;
    const int localY = position.y % CHUNK_SIZE;

    Chunk& chunk = chunks[chunkY * widthInChunks + chunkX];

    return &chunk.getCell(localX, localY);
}

const Cell* World::tryGetCell(GridPosition position) const
{
    if (!isInside(position))
        return nullptr;

    const int chunkX = position.x / CHUNK_SIZE;
    const int chunkY = position.y / CHUNK_SIZE;

    const int localX = position.x % CHUNK_SIZE;
    const int localY = position.y % CHUNK_SIZE;

    const Chunk& chunk = chunks[chunkY * widthInChunks + chunkX];

    return &chunk.getCell(localX, localY);
}

bool World::isWalkable(GridPosition position) const
{
    const Cell* cell = tryGetCell(position);

    if (cell == nullptr) return false;

    return cell -> tileType != TileType::Water &&
        cell -> tileType != TileType::Stone;
}
