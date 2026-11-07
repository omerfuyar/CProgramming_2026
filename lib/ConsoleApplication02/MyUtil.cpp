#include "MyUtil.h"
#include <strsafe.h>

const int g_width = 80;
const int g_height = 25;
HWND g_hwndConsole = 0;
HANDLE g_hConsole = 0;
char g_buffer[g_height][g_width + 1];

void GotoXY(int x, int y)
{
    _COORD pos{ (short)x,(short)y };
    SetConsoleCursorPosition(g_hConsole, pos);
}

void ShowCursor(bool visible)
{
    CONSOLE_CURSOR_INFO cursorInfo{ 1,visible };
    SetConsoleCursorInfo(g_hConsole, &cursorInfo);
}

void PutCh(int x, int y, char ch)
{
    if (x >= 0 && x < g_width && y >= 0 && y <= g_height)
        g_buffer[y][x] = ch;
}

void PutText(int x, int y, const char* text)
{
    const size_t len = strlen(text);
    if (x + len >= g_width) return;
    const char oldCh = g_buffer[y][x + len];
    sprintf_s(&g_buffer[y][x], __min(len+1,g_width - x), text);
    g_buffer[y][x + len] = oldCh;
}

void PutTextf(int x, int y, const char* format_, ...)
{
    char    buffer[1024];
    va_list argList;

    va_start(argList, format_);
    StringCchVPrintfA(buffer, 1024, format_, argList);
    va_end(argList);
    PutText(x, y, buffer);
}//PutTextf()

void ClearBuffer()
{
    memset(g_buffer, ' ', sizeof(g_buffer));
    for (int row = 0; row < g_height; ++row) {
        g_buffer[row][g_width] = 0;
    }
}

void DrawBuffer()
{
    for (int row = 0; row < g_height; ++row) {
        GotoXY(0, row);
        printf(g_buffer[row]);
    }
}
