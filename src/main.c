#include <stdlib.h>
#include "screen.h"

int main() {

    ScreenBuffer sb = createScreenBuffer(100+(100*2)/2,56 , 0,0);
    setScreenActive(sb);

    while(1){
        writeScreen(sb);
    }

    return 0;

}
