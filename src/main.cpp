#include <iostream>

#include "Darkjack.hpp"
#include "utils.hpp"

int main() {
    clearScreen();

    dark::Player p("ruezomon", 1000);
    p.bet(200);
    return 0;
}