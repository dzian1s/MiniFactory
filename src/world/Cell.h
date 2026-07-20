#pragma once
#include "Types.h"

struct GridPosition
{
    int x=0;
    int y=0;
};

struct Cell 
{
    GridPosition position;
    TileType tileType = TileType::EMPTY;
};
