#include    "main.h"
#include    "Application.h"
#include <Windows.h>
#include <iostream>

int main(void)
{
#if defined(DEBUG) || defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_HIDE);
#endif

    Application app(SCREEN_WIDTH, SCREEN_HEIGHT);
    app.Run();
    return 0;
}