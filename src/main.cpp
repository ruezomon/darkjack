#include <iostream>
#include <cstdlib>
#include <csignal>

#include "Darkjack.hpp"
#include "utils.hpp"
#include "ColorDefinitions.hpp"

int main() {

    signal(SIGINT, [](int s) {
        clearScreen();
        std::cout << CYAN << "Don't wanna play? Scram!" << RESET << std::endl; 
        exit(0);
    });

    clearScreen();
    std::string name;

    // intro
    std::cout << CYAN << "Welcome to darkjack! Ruezomons Blackjack port for Terminal" << std::endl;
    std::cout << "Please enter your name: " << RESET << std::flush;
    std::cin >> name;
    printRules(name);

    // initialization
    dark::Player player(name, 1000);
    

    // game loop
    while (true) {
        std::cout << CYAN << "Current balance for " << name << ": " << player.getBudget() << "$" << std::endl;
        if (player.getBudget() == 0) {
            std::cout << "It seems as if you're broke! Get lost!" << RESET << std::endl;
            break;
        }
        
        if (player.getBudget() >= 100000) {
            std::cout << "It seems as if you've won! The Casino can't cover this amount of money, so get lost!" << RESET << std::endl;
            break;
        }

        // get bet
        uint16_t bet = getBet(player.getBudget());

        std::cout << "-----------------------------------------------" << RESET << std::endl << std::endl;
        player.bet(bet);
        std::cout << CYAN << "-----------------------------------------------" << RESET << std::endl << std::endl;
    }

    return 0;
}