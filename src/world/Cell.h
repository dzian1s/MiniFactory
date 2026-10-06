#pragma once

enum class TileType
{
    Grass,
    Stone,
    Water,
    Iron,
};

enum class ResourceType
{
    None,
};

struct GridPosition
{
    int x=0;
    int y=0;
};

struct Cell 
{
    GridPosition position;

    TileType tileType = TileType::Grass;
    ResourceType resourceType = ResourceType::None;

    int resourceAmount = 0;
};
