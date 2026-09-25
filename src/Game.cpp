#include <iostream>

#include "Darkjack.hpp"
#include "ColorDefinitions.hpp"

dark::Game::Game(dark::Player* p) : player(p), stack(new dark::Stack()) {}

dark::Game::~Game() {
    delete stack;
}

void dark::Game::start() noexcept {
    drawCardsDealer(2);
    printDealerCards();
    player->giveCard(false);
    player->giveCard(true);

    if (getDealerSum() >= 21) this->instantFinishGame();

    player->queryMove();
}

void dark::Game::reshuffle() noexcept {
    this->stack->shuffle();
    this->dealerStack.clear();
}

dark::Card dark::Game::drawCard() noexcept {
    return this->stack->draw();
}

void dark::Game::drawCardsDealer(uint8_t n) noexcept {
    for (uint8_t i = 0; i < n; i++) {
        this->dealerStack.push_back(this->stack->draw());
    }
}

uint8_t dark::Game::getDealerSum() const noexcept {
    uint8_t n = 0;
    uint8_t aces = 0;
    for (auto i : dealerStack) {
        n += i.getValue();
        if (i.getImage() == 1) aces++;
    }

    uint8_t c = 0;
    while (n > 21 && c < aces) { n -= 10; c++; }

    return n;
}

void dark::Game::instantFinishGame() {
    if (getDealerSum() == 21) {
        std::cout << std::endl 
                  << "Dealer got Blackjack!" << std::endl;
        player->lose();
    } else if (getDealerSum() > 21) {
        std::cout << std::endl 
                  << "Dealer busted!" << std::endl;
        player->win();
    } else {
        throw "game ended too early";
    }
}

void dark::Game::finishGame() noexcept {
    drawRestOfDealerCards();
    printDealerCards();

    uint8_t playerSum = player->getSum();
    uint8_t dealerSum = getDealerSum();

    if (playerSum > 21) player->bust();
    else if (dealerSum > 21 || playerSum > dealerSum) player->win();
    else if (playerSum == dealerSum) player->push();
    else player->lose();
}

void dark::Game::drawRestOfDealerCards() noexcept {
    while (getDealerSum() < 17)
        drawCardsDealer(1);
}

void dark::Game::printDealerCards() noexcept {
    std::cout << RED << std::flush;
    std::cout << "Dealers cards: " << std::endl;
    for (auto i : dealerStack) {
        std::cout << i.getFullName() << std::endl;
    }
    std::cout << "Sum: " << static_cast<int>(getDealerSum()) << std::endl;
    std::cout << RESET << std::endl;
}
