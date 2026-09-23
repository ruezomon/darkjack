#include "Darkjack.hpp"

dark::Game::Game(dark::Player* p) : player(p) {}

void dark::Game::start() {
    this->playerWatcher = new std::thread([this]() {
        while (true) {
            if (this->player->hasTurn()) this->player->queryMove();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });
}
