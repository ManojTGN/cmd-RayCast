#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
// #include <stdarg.h>
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

typedef struct PartialScreenBuffer{
    int width;
    int height;

    COORD writeAt;

    char* screen;
} PartialScreenBuffer;

ScreenBuffer createScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y);
PartialScreenBuffer createPartialScreenBuffer(int width, int height, int writeAt_X, int writeAt_Y);

bool writeScreen(ScreenBuffer sb);
bool writePartialScreen(ScreenBuffer *sb, PartialScreenBuffer psb);

void setScreenActive(ScreenBuffer sb);

#endif /* SCREEN_H */
