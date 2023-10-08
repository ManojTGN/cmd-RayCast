
#ifndef MAP_H
#define MAP_H

#include "screen.h"

#define CHUNK_SIZE = 10;
#define WALL_HEIGHT = 50;
#define DRAW_DISTANCE = 2; //chunk around player

enum TileType {
    EMPTY = 0,
    WALL,
    PLAYER
};

typedef struct map {
    int width;
    int height;
    enum TileType* map;

    char c_player = 'P';
    char c_wall = '#';
    char c_empty = ' ';
} MAP;

MAP createRandomMap(int width, int height);
bool writeMapToPartialScreenBuffer(PartialScreenBuffer *map_b , MAP map_m);

#endif /* MAP_H */
