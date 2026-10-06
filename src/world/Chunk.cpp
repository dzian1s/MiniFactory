#include <raylib.h>

#include "Chunk.h"
#include "Config.h"
#include "world/Cell.h"

Chunk::Chunk(int chunkX, int chunkY)
    :chunkX(chunkX)
    ,chunkY(chunkY)
    ,cells (CHUNK_SIZE*CHUNK_SIZE)
{
    generate();
}

void Chunk::generate()
{
    const int offsetX = chunkX * CHUNK_SIZE;
    const int offsetY = chunkY * CHUNK_SIZE;

    Image Noise = GenImagePerlinNoise(CHUNK_SIZE, CHUNK_SIZE, offsetX, offsetY, 4.0f);

    Color* pixels = LoadImageColors(Noise);

    for (int y = 0; y < CHUNK_SIZE; ++y)
    {
        for(int x = 0; x < CHUNK_SIZE; ++x)
        {
            Cell& cell = getCell(x, y);

            cell.position = {offsetX + x, offsetY + y};

            const Color noiseColor = pixels[y * CHUNK_SIZE + x];

            const float value = noiseColor.r / 255.0f;

            if (value < 0.35f) cell.tileType = TileType::Water;
            else if (value > 0.9f) cell.tileType = TileType::Iron;
            else if (value > 0.75f) cell.tileType = TileType::Stone; 
            else cell.tileType = TileType::Grass;
        }
    }

    UnloadImageColors(pixels);
    UnloadImage(Noise);
}

void Chunk::render() const
{
    for (int y = 0; y < CHUNK_SIZE; ++y)
    {
        for (int x = 0; x < CHUNK_SIZE; ++x)
        {
            const Cell& cell = getCell(x,y);

            const int screenX = cell.position.x * TILE_SIZE;
            const int screenY = cell.position.y * TILE_SIZE;

            Color cellColor = LIGHTGRAY;

            switch (cell.tileType)
            {
                case TileType::Grass:
                    cellColor = DARKGREEN;
                    break;

                case TileType::Iron:
                    cellColor = BEIGE;
                    break;

                case TileType::Stone:
                    cellColor = DARKGRAY;
                    break;

                case TileType::Water:
                    cellColor = BLUE;
                    break;
            }

            DrawRectangle(screenX, screenY, TILE_SIZE, TILE_SIZE, cellColor);

            DrawRectangleLines(screenX, screenY, TILE_SIZE, TILE_SIZE, GRAY);
        }
    }
}

Cell& Chunk::getCell(int x, int y)
{
    return cells[y * CHUNK_SIZE + x];
}

const Cell& Chunk::getCell(int x, int y) const
{
    return cells[y * CHUNK_SIZE + x];
}
