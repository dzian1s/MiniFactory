#pragma once

#include <raylib.h>
#include <vector>
#include "Cell.h"

class World
{
public:
    World(int width, int height);

    void update (float dt);
    void render() const;

private:
    int width;
    int height;

    std::vector<Cell> cells;

private:
    Cell& getCell(int x, int y) ;
    const Cell& getCell(int x, int y) const;

    GridPosition screenToGrid(Vector2 screenPos) const;
    bool isInside(GridPosition position) const;
    void createCells();
};
