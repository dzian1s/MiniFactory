#pragma once

#include <raylib.h>
#include <vector>
#include "Cell.h"
#include "Chunk.h" 

class World
{
public:
    World(int widthInChunks, int heightInChunks);

    void update (float dt);
    void render(const Camera2D& camera) const;
    Cell* tryGetCell(GridPosition position);
    const Cell* tryGetCell(GridPosition position) const;
    bool isWalkable (GridPosition position) const;

private:
    int widthInChunks;
    int heightInChunks;

    std::vector<Chunk> chunks;

private:
    GridPosition screenToGrid(Vector2 screenPos, const Camera2D& camera) const;
    bool isInside(GridPosition position) const;
    void createCells();
    void generateMap();
};
