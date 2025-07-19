#pragma once
#include <Windows.h>

constexpr WORD KEY_MANA_POTION   = VK_F1;
constexpr WORD KEY_HP_POTION     = VK_F2;
constexpr WORD KEY_HP_SPELL     = VK_F3;
constexpr WORD KEY_BUFF_SPELL_1  = VK_F4;
constexpr WORD KEY_BUFF_SPELL_2 = VK_F5;

constexpr float manaPercentageThreshold = 0.80f;
constexpr float hpPercentageThreshold   = 0.95f;

constexpr int manaCheckIntervalMs = 1050;
constexpr int hpCheckIntervalMs   = 700;
constexpr int buffInterval1Sec    = 15;
constexpr int buffInterval2Sec    = 30;
constexpr int buffInterval3Sec    = 14;

bool paused = false;