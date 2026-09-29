#pragma once

#include <string>
#include <cstdint>

void clearScreen() noexcept;
uint16_t parseInt(std::string s) noexcept;
void printRules(std::string name) noexcept;
uint16_t getBet(uint16_t playerBudget) noexcept;
