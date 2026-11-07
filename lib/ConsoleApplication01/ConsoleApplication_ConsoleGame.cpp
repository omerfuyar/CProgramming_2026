#include "MyUtil.h"
#include <cwchar>
#define _USE_MATH_DEFINES
#include <cmath>
#include <complex>
#include <Windows.h>
#include <WinUser.h>
#include <strsafe.h>
#include <vector>

#define ESC_KEY     27

void Update(double elapsedTime)
{
    PutTextf(0, 0, "%g", elapsedTime);
    //
    // game object update logic here
    //
}

void DrawGameWorld() {
    //
    // game object drawing routine here
    //
    PutText(1, 1, "No Flickering!");
    DrawBuffer();
}

int main(void)
{
    g_hwndConsole = GetConsoleWindow();
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ShowCursor(false);

    bool isGameLoop = true;
    clock_t prevClock = clock();
    clock_t currClock = prevClock;
    int i = 1;

    while (isGameLoop == true)
    {
        if( _kbhit() ){
            int ch = 0;
            ch = _getch();
            if (ch == ESC_KEY )
                isGameLoop = false;
        }
        prevClock = currClock;
        currClock = clock();
        const double elapsedTime = ((double)currClock - (double)prevClock) / CLOCKS_PER_SEC;
        ClearBuffer();
        Update(elapsedTime);
        Sleep(10);
        DrawGameWorld();
    }
}
