#include "input_simulator.h"

void PressKey(WORD key) 
{
    keybd_event((BYTE)key, 0, 0, 0);
    Sleep(50);
    keybd_event((BYTE)key, 0, KEYEVENTF_KEYUP, 0);
}