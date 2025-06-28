#pragma once
#include <Windows.h>
#include <vector>

int ReadIntWithOffsets(HANDLE process, uintptr_t baseAddr, const std::vector<unsigned int>& offsets);