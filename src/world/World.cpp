#include "World.h"
#include "Cell.h"
#include "Config.h"
#include <raylib.h>

World::World(int width, int height)
    : width(width)
    , height(height)
    , cells (width*height)
{
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
           getCell(x, y).position = {x, y}; 
}

void World::update(float dt)
{

}

void World::render() const
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            const Cell& cell = getCell(x, y);

            int screenX = cell.position.x * TILE_SIZE;
            int screenY = cell.position.y * TILE_SIZE;

            DrawRectangle(screenX, screenY, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
            DrawRectangleLines(screenX, screenY, TILE_SIZE, TILE_SIZE, GRAY);
        }
    }

    const auto mousePos = GetMousePosition();
    const auto hoveredCell = screenToGrid(mousePos);

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

Cell& World::getCell(int x, int y) 
{
    return cells[y * width + x];
}

const Cell& World::getCell(int x, int y) const
{
    return cells [y * width + x];
}

GridPosition World::screenToGrid(Vector2 screenPos) const
{
    return 
    {
        static_cast<int>(screenPos.x)/TILE_SIZE,
        static_cast<int>(screenPos.y)/TILE_SIZE
    };
}

bool World::isInside(GridPosition position) const
{
    return position.x >= 0 &&
           position.y >= 0 &&
           position.x < width &&
           position.y < height;
}

void World::createCells()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {    
            
        }
    }
}
