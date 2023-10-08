#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

typedef struct ScreenBuffer{

    int width;
    int height;

    COORD writeAt;
    SMALL_RECT writeArea;

    char* screen;
    HANDLE hConsole;
    DWORD dwBytesWritten;

} ScreenBuffer;

// typedef struct PartialScreenBuffer{
//     int width;
//     int height;

//     COORD coord;

//     char* screen;
// } PartialScreenBuffer;

ScreenBuffer createScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y);

// bool mergeScreenBuffer(ScreenBuffer* sb, PartialScreenBuffer psbs);
bool writeScreen(ScreenBuffer sb);

void clearScreen(ScreenBuffer* sb);
void setScreenActive(ScreenBuffer sb);
// void clearPartialScreen(PartialScreenBuffer* psb);

#endif /* SCREEN_H */
