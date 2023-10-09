#include "screen.h"

ScreenBuffer createScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y) {

    ScreenBuffer sb;

    sb.width = width;
    sb.height = height;
    sb.writeAt.X = writeAt_X;
    sb.writeAt.Y = writeAt_Y;
    sb.dwBytesWritten = 0;

    sb.screen = (char*)malloc(width * height);
    for(int h = 0; h < height; h++)
    for(int w = 0; w < width; w++)
    sb.screen[h*width + w] = ' ';

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

PartialScreenBuffer createPartialScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y){
    PartialScreenBuffer psb;
    psb.width = width;
    psb.height = height;
    psb.writeAt.X = writeAt_X;
    psb.writeAt.Y = writeAt_Y;

    psb.screen = (char*)malloc(width * height);
    for(int w = 0; w < width; w++)
    for(int h = 0; h < height; h++)
    psb.screen[w*height + h] = ' ';

    psb.screen[width*height -1] = '\0';
    return psb;
}

bool writeScreen( ScreenBuffer sb ){
    BOOL fSuccess = WriteConsoleOutputCharacter(sb.hConsole, sb.screen, sb.width * sb.height, sb.writeAt, &sb.dwBytesWritten);
    return fSuccess;
}

void setScreenActive(ScreenBuffer sb){
    SetConsoleActiveScreenBuffer(sb.hConsole);
}

bool writePartialScreen(ScreenBuffer *sb, PartialScreenBuffer psb){
    if(psb.writeAt.X < 0 || psb.writeAt.Y < 0 || psb.writeAt.X>sb->width || psb.writeAt.Y>sb->height) return false;

    int tmp;
    for(int w = 0; w < psb.width; w++){
    for(int h = 0; h < psb.height; h++){
        tmp = (psb.writeAt.X+w)*sb->width + (psb.writeAt.Y+h);
        if( tmp < 0 || tmp > sb->width*sb->height-1 ) continue;
        sb->screen[tmp] = psb.screen[w*psb.height +h];
    }
    }

    return true;
}
