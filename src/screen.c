#include "screen.h"

ScreenBuffer createScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y) {

    ScreenBuffer sb;

    sb.width = width;
    sb.height = height;
    sb.writeAt.X = writeAt_X;
    sb.writeAt.Y = writeAt_Y;
    sb.dwBytesWritten = 0;

    sb.screen = (char*)malloc(width * height);
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
            if(w == 0 || h == 0 || w == width-1 || h == height-1) sb.screen[h*width + w] = '0';
            else sb.screen[h*width + w] = ' ';
        }
    }

    sb.screen[height*width - 1] = '\0';
    sb.hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    SMALL_RECT const minimal_window = { 0, 0, 1, 1 };
    SetConsoleWindowInfo(sb.hConsole, TRUE, &minimal_window);

    COORD bufferSize = { (SHORT)width, (SHORT)height };
    SetConsoleScreenBufferSize(sb.hConsole, bufferSize);

    sb.writeArea.Top = sb.writeArea.Left = 0;
    sb.writeArea.Bottom = height - 1;
    sb.writeArea.Right = width - 1;
    SetConsoleWindowInfo(sb.hConsole, TRUE, &sb.writeArea);

    return sb;

}

bool writeScreen( ScreenBuffer sb ){

    BOOL fSuccess = WriteConsoleOutputCharacter(sb.hConsole, sb.screen, sb.width * sb.height, sb.writeAt, &sb.dwBytesWritten);

    return fSuccess;

}

void setScreenActive(ScreenBuffer sb){

    SetConsoleActiveScreenBuffer(sb.hConsole);

}

void clearScreen( ScreenBuffer* sb ){
    
}

// void clearPartialScreen( PartialScreenBuffer* psb ){
    
// }
