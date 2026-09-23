#include "Darkjack.hpp"

dark::Player::Player(uint16_t budget) : budget(budget), game(new dark::Game(this)) {}

void dark::Player::addBudget(uint16_t amount) noexcept {
    this->budget += amount;
}

bool dark::Player::bet(uint16_t amount) noexcept {
    if (amount > budget) return false;
    this->currentBet = amount;
    this->budget -= amount;

    this->play();
}

bool dark::Player::doubleDown() noexcept {
    this->currentBet *= 2;
}

void dark::Player::play() noexcept {
    playerCardStacks.push_back(std::vector<dark::Card>());
    game->start();
}

bool dark::Player::hit() noexcept {

}

void dark::Player::stand() noexcept {

}

bool dark::Player::split(uint8_t deck) noexcept {
    if (!this->splittable(deck)) return false;

    Card c = playerCardStacks[deck].back();
    playerCardStacks[deck].pop_back();
    playerCardStacks.insert(playerCardStacks.begin() + deck + 1, std::vector<dark::Card>({c}));
    return true;
}

bool dark::Player::splittable(uint8_t deck) const noexcept {
    return 
        this->playerCardStacks.size() > deck && 
        this->playerCardStacks[deck].size() == 2 && 
        this->playerCardStacks[deck][0].getImage() == this->playerCardStacks[deck][1].getImage();
}

bool dark::Player::judge(uint8_t stack) const noexcept {

}

uint8_t dark::Player::getStackSum(uint8_t stack) const noexcept {
    uint8_t sum = 0;
    uint8_t aceAmount = 0;
    for (dark::Card i : playerCardStacks[stack]) {
        sum += i.getValue();
        if (i.getImage() == 1) aceAmount++;
    }

    uint8_t i = 0;
    while (sum > 21 && i < aceAmount) {
        sum -= 10;
    }
}

void dark::Player::win() noexcept {
    budget += currentBet * 2;
    currentBet = 0;
    clearCards();
}

void dark::Player::bust() noexcept {
    currentBet = 0;
    clearCards();
}

void dark::Player::clearCards() noexcept {
    playerCardStacks.clear();
}

bool dark::Player::hasTurn() const noexcept {
    return this->turn;
}

void dark::Player::queryMove() noexcept {
    
}
