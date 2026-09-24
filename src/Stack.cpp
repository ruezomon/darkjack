#include <random>
#include <ctime>

#include "Darkjack.hpp"

dark::Stack::Stack() noexcept {
    srand(time(NULL));
    this->cardTemplateArray = new dark::Card[52];

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 13; j++) {
            this->cardTemplateArray[i * 13 + j] = dark::Card(i, j + 1);
        }
    }

    this->shuffle();
}

void dark::Stack::shuffle() noexcept {
    this->cardstack->clear();

    bool used[52] = {false};
    for (uint8_t i = 0; i < 52; i++) {
        uint8_t currentIndex;
        do {
            currentIndex = rand() % 52;
        } while (used[currentIndex]);

        used[currentIndex] = true;
        this->cardstack->push_back(cardTemplateArray[currentIndex]);
    }
}

dark::Card dark::Stack::draw() noexcept {
    if (!this->canDraw()) return dark::Card();
    dark::Card c = this->cardstack->back();
    this->cardstack->pop_back();
    return c;
}

bool dark::Stack::canDraw() noexcept {
    return !this->cardstack->empty();
}
