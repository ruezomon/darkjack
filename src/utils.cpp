#include <iostream>

#include "utils.hpp"

void clearScreen() {
    std::cout << "\033[H\033[2J" << std::flush;
}
