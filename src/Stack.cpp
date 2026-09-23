#include <random>

#include "Stack.hpp"

dark::Stack::Stack() noexcept {
    srand(time(NULL));

    for (uint8_t i = 0; i < 4; i++) {
        for (uint8_t j = 0; j < 13; j++) {
            this->cardTemplateArray[i * 13 + j] = dark::Card(i, j);
        }
    }

    this->shuffle();
}

void dark::Stack::shuffle() noexcept {
    this->cardstack->clear();

    uint8_t* used = new uint8_t[52]{0};
    uint8_t currentIndex = 0;
    bool foundUnique = false;
    for (uint8_t i = 0; i < 52; i++) {
        do {
            currentIndex = rand() % 52;
            for (int j = 0; j < 52; j++) {
                if (used[j] == currentIndex) foundUnique = false;
                break;
            }
        } while (!foundUnique);
        this->cardstack->push_back(cardTemplateArray[currentIndex]);
        used[i] = currentIndex;
    }

    delete[] used;
}


dark::Card dark::Stack::draw() noexcept {
    if (!this->canDraw()) return dark::Card();
    return this->cardstack->back();
}

bool dark::Stack::canDraw() noexcept {
    return !this->cardstack->empty();
}
