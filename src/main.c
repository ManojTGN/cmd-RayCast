#include <stdlib.h>
#include "screen.h"
#include "map.h"

int main() {
    ScreenBuffer sb = createScreenBuffer(100+(100*2)/2,56 , 0,0);
    PartialScreenBuffer map_b = createPartialScreenBuffer(10,20, 0,0);
    MAP map_m = createRandomMap(10,20);

    setScreenActive(sb);

    while(1){
        writeMapToPartialScreenBuffer(&map_b,map_m);
        writePartialScreen(&sb,map_b);
        writeScreen(sb);
    }

    return 0;
}
