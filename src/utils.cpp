#include <iostream>
#include <cstdint>
#include <string>

#include "utils.hpp"
#include "ColorDefinitions.hpp"

void clearScreen() noexcept {
    std::cout << "\033[H\033[2J" << std::flush;
}

uint16_t parseInt(std::string s) noexcept {
    for (char c : s) {
        if (c < '0' || c > '9') {
            return 0;
        }
    }
    return std::stoi(s);
}

void printRules(std::string name) noexcept {
    std::cout << CYAN << "Player with name " << name << " registered." << std::endl << std::endl;
    std::cout << "You will start with 1000$. You goal is to 'work' yourself up to 100.000$" << std::endl;
    std::cout << "Once you reach 0$ its game over. " << RESET << std::endl << std::endl << std::endl;
}

uint16_t getBet(uint16_t playerBudget) noexcept {
    std::string betS = "";
    uint16_t bet = 0;
    bool validBet = true;
    do {
        std::cout << "Enter your next bet: " << std::flush;
        std::cin >> betS;
        bet = parseInt(betS);
        validBet = bet != 0 && bet <= playerBudget;
    } while (!validBet);
    return bet;
}
