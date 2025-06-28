#pragma once
#include <Windows.h>

constexpr WORD KEY_MANA_POTION = VK_F1;
constexpr WORD KEY_HP_POTION   = VK_F2;
constexpr WORD KEY_HP_SPELL    = VK_F3;
constexpr WORD KEY_BUFF_SPELL  = VK_F4;

constexpr float manaPercentageThreshold = 0.75f;
constexpr float hpPercentageThreshold   = 0.87f;

constexpr int manaCheckIntervalMs = 1050;
constexpr int hpCheckIntervalMs   = 700;
constexpr int buffInterval1Sec    = 31;
constexpr int buffInterval2Sec    = 60;

bool paused = false;