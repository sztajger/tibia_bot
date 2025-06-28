#include "memory_reader.h"

int ReadIntWithOffsets(HANDLE process, uintptr_t baseAddr, const std::vector<unsigned int>& offsets) {
    uintptr_t addr = baseAddr;
    for (auto offset : offsets) {
        ReadProcessMemory(process, (BYTE*)addr, &addr, sizeof(addr), nullptr);
        addr += offset;
    }
    int value = 0;
    ReadProcessMemory(process, (BYTE*)addr, &value, sizeof(value), nullptr);
    return value;
}