#include "config/settings.h"
#include "window_utils.h"
#include "process_utils.h"
#include "input_simulator.h"
#include "memory_reader.h"
#include <chrono>
#include <iostream>

int main() {
    HWND hwnd = FindTibiaWindow();
    if (!hwnd) return 1;

    DWORD pid = GetPidFromWindow(hwnd);
    HANDLE hProc = OpenTibiaProcess(pid);
    if (!hProc) return 1;

    uintptr_t base = GetModuleBaseAddress(pid, "IglaOTS.exe");

    uintptr_t baseMana = base + 0x19852A8;
    std::vector<unsigned int> currentManaOffsets = { 0xD8, 0x60 };
    std::vector<unsigned int> maxManaOffsets = { 0x78, 0x8, 0x60, 0x8, 0x188, 0x28, 0x84 };

    uintptr_t baseHp = base + 0x19852A8;
    std::vector<unsigned int> currentHpOffsets = { 0xE0, 0x28 };
    std::vector<unsigned int> maxHpOffsets = { 0xD8, 0x1C };

    auto lastHpCheck = std::chrono::steady_clock::now();
    auto lastManaCheck = std::chrono::steady_clock::now();
    auto lastBuff1 = std::chrono::steady_clock::now();
    auto lastBuff2 = std::chrono::steady_clock::now();

    while (true) {
        if (GetAsyncKeyState('P') & 0x8000) 
		{
            paused = !paused;
            std::cout << (paused ? "[Pasue]" : "[UnPause]") << std::endl;
            Sleep(500); // Unikaj spamowania
        }

        if (paused) {
            Sleep(100);
            continue;
        }

        auto now = std::chrono::steady_clock::now();

        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastHpCheck).count() > hpCheckIntervalMs) {
            lastHpCheck = now;
            int curHp = ReadIntWithOffsets(hProc, baseHp, currentHpOffsets);
            int maxHp = ReadIntWithOffsets(hProc, baseHp, maxHpOffsets);
            if (maxHp > 0 && curHp < maxHp * hpPercentageThreshold)
                PressKey(KEY_HP_POTION);
        }

        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastManaCheck).count() > manaCheckIntervalMs) {
            lastManaCheck = now;
            int curMana = ReadIntWithOffsets(hProc, baseMana, currentManaOffsets);
            int maxMana = ReadIntWithOffsets(hProc, baseMana, maxManaOffsets);
            if (maxMana > 0 && curMana < maxMana * manaPercentageThreshold)
                PressKey(KEY_MANA_POTION);
        }

        if (std::chrono::duration_cast<std::chrono::seconds>(now - lastBuff1).count() > buffInterval1Sec) {
            lastBuff1 = now;
            PressKey(KEY_HP_SPELL);
        }
        if (std::chrono::duration_cast<std::chrono::seconds>(now - lastBuff2).count() > buffInterval2Sec) {
            lastBuff2 = now;
            PressKey(KEY_BUFF_SPELL);
        }

        Sleep(20);
    }

    CloseHandle(hProc);
    return 0;
}
