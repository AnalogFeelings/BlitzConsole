#include "ConsoleLib.h"

CMDLIB(void) CreateConsole(const char* consoleTitle, const char* window, int hideWindow)
{
    CONSOLE_SCREEN_BUFFER_INFO cmdinf;
    b3d = (HWND)atoi(window);

    AllocConsole(); //Allocate a CMD window.
    console = GetConsoleWindow();
    freopen("CONOUT$", "w+", stdout);
    out = CreateFileW(L"CONOUT$", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                      0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

    SetStdHandle(STD_OUTPUT_HANDLE, out);
    stdhandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(console, ENABLE_VIRTUAL_TERMINAL_INPUT);

    BringWindowToTop(console);
    if(GetConsoleScreenBufferInfo(stdhandle, &cmdinf))
    {
        cmdinf.dwSize.Y = 1000;
        SetConsoleScreenBufferSize(stdhandle, cmdinf.dwSize);
    }
    SetConsoleTitleA(consoleTitle); //Set the console title.
    if(hideWindow == 1) { SetFocus(b3d); ShowWindow(b3d, SW_HIDE); }
}

CMDLIB(void) ConsoleLog(const char* message, int color)
{
    SetConsoleTextAttribute(stdhandle, color);
    std::cout << message << "\n";
}

CMDLIB(void) ConsoleTitle(const char* title)
{
    SetConsoleTitleA(title);
}

CMDLIB(void) BringGraphicsBack()
{
    ShowWindow(b3d, SW_SHOW);
}