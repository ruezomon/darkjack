#include "Darkjack.hpp"

dark::Game::Game(dark::Player* p) : player(p), stack(new dark::Stack()) {}

dark::Game::~Game() {
    delete stack;
    delete playerWatcher;
}

void dark::Game::start() {
    this->playerWatcher = new std::thread([this]() {
        bool playerPlayed = false;
        while (true) {
            if (this->player->hasTurn()) {
                this->player->queryMove(); 
                playerPlayed = true;
            } else if (playerPlayed) {
                this->finishGame();
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });
    playerWatcher->detach();
}

void dark::Game::reshuffle() noexcept {
    this->stack->shuffle();
    this->dealerStack.clear();
}

dark::Card dark::Game::drawCard() noexcept {
    return this->stack->draw();
}

void dark::Game::drawCardsDealer(uint8_t n) {
    for (uint8_t i = 0; i < n; i++) {
        this->dealerStack.push_back(this->stack->draw());
    }
}
