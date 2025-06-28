#include "window_utils.h"
#include <cstring>

HWND FindTibiaWindow() 
{
    HWND hwnd = nullptr;
    EnumWindows([](HWND hWnd, LPARAM lParam) -> BOOL 
    {
        char title[256];
        GetWindowTextA(hWnd, title, sizeof(title));
        if (strstr(title, "Tibia") != nullptr) 
        {
            *(HWND*)lParam = hWnd;
            return FALSE;
        }
        return TRUE;
    }, 
    (LPARAM)&hwnd);
    return hwnd;
}