#pragma once

#include "Cell.h"
#include <vector>

class Chunk
{
private:
    int chunkX;
    int chunkY;

    std::vector<Cell> cells;

public:
    Chunk (int chunkX, int chunkY);

    void generate();
    void render() const;

    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;
};
