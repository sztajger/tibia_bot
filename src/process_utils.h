#pragma once
#include <Windows.h>

DWORD GetPidFromWindow(HWND hwnd);
HANDLE OpenTibiaProcess(DWORD pid);
uintptr_t GetModuleBaseAddress(DWORD procId, const char* modName);