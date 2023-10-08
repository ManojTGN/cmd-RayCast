#include "map.h"
#include <stdbool.h>

MAP createRandomMap(int width, int height) {
    //todo: make a random map generator;
    //for now it will generate only one default map for testing

    MAP map;
    map.width = width;
    map.height = height;
    map.map = (enum TileType*) malloc(height*width*sizeof(enum TileType));

    for(int w = 0; w < width; w++)
    for(int h = 0; h < height; h++){
        if(h == 0 || w == 0 || h == height-1 || w == width-1) map.map[w*height +h] = WALL;
        else map.map[w*height +h] = EMPTY;
    }

    return map;

}

bool writeMapToPartialScreenBuffer(PartialScreenBuffer *map_b, MAP map_m){
    if(map_b->height != map_m.height || map_b->width != map_m.width) return false;

    for(int w = 0; w < map_b->width; w++)
    for(int h = 0; h < map_b->height; h++)
    map_b->screen[w*map_b->height + h] = map_m.map[w*map_b->height + h] == EMPTY?map_m.c_empty:
                                         map_m.map[w*map_b->height + h] == WALL ?map_m.c_wall:
                                         map_m.map[w*map_b->height + h] == PLAYER?map_m.c_player:map_m.c_empty;

    return true;
}
