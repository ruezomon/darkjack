#include <iostream>
#include <string>

#include "Darkjack.hpp"
#include "ColorDefinitions.hpp"

dark::Player::Player(std::string n, uint16_t budget) noexcept : budget(budget), game(new dark::Game(this)), name(n) {}

dark::Player::~Player() { delete this->game; }

void dark::Player::addBudget(uint16_t amount) noexcept {
    this->budget += amount;
}

uint16_t dark::Player::getBudget() const noexcept {
    return this->budget;
}

void dark::Player::printCards() const noexcept {
    std::cout << BLUE << std::flush;
    std::cout << name << "'s cards: " << std::endl;
    for (auto card : playerCardStack) {
        std::cout << card.getFullName() << std::endl;
    }
    std::cout << "Sum: " << static_cast<int>(getSum()) << std::endl;
    std::cout << RESET << std::endl;
}

bool dark::Player::bet(uint16_t amount) noexcept {
    if (amount > budget) return false;
    this->currentBet = amount;
    this->budget -= amount;
    std::cout << name << " has bet " << currentBet << "$" << std::endl;

    this->play();
    return true;
}

bool dark::Player::canDoubleDown() const noexcept {
    return this->budget > this->currentBet;
}

bool dark::Player::doubleDown() noexcept {
    if (!canDoubleDown()) return false;
    this->budget -= this->currentBet;
    this->currentBet *= 2;
    std::cout << name << " has raised their bet to " << currentBet << "$" << std::endl;
    return true; 
}

void dark::Player::play() noexcept {
    game->start();
}

void dark::Player::hit() noexcept {
    bool queryForNextMove = true;
    playerCardStack.push_back(this->game->drawCard());
    if (this->getSum() == 21) queryForNextMove = false;
    else if (this->getSum() > 21) queryForNextMove = false;
    else queryForNextMove = true;

    printCards();

    if (queryForNextMove) queryMove();
    else stand();
}

void dark::Player::giveCard(bool verbal) noexcept {
    playerCardStack.push_back(this->game->drawCard());
    if (verbal) printCards();
}

void dark::Player::stand() noexcept {
    game->finishGame();
}

uint8_t dark::Player::getSum() const noexcept {
    uint8_t sum = 0;
    uint8_t aceAmount = 0;
    for (dark::Card i : playerCardStack) {
        sum += i.getValue();
        if (i.getImage() == 1) aceAmount++;
    }

    uint8_t i = 0;
    while (sum > 21 && i < aceAmount) {
        sum -= 10;
        i++;
    }
    return sum;
}

void dark::Player::win() noexcept {
    std::cout << name << " has won!" << std::endl;

    budget += currentBet * 2;
    currentBet = 0;
    clearCards();
}

void dark::Player::bust() noexcept {
    std::cout << name << " has busted!" << std::endl;
    lose();
}

void dark::Player::lose() noexcept {
    currentBet = 0;
    std::cout << name << " has lost!" << std::endl;
    clearCards();
}

void dark::Player::push() noexcept {
    budget += currentBet;
    currentBet = 0;
    std::cout << name << " has pushed!" << std::endl;
    clearCards();
}

void dark::Player::clearCards() noexcept {
    playerCardStack.clear();
}

void dark::Player::queryMove() noexcept {
    std::string userInput = "";
    bool inputValid = false;
    bool hit;
    bool _canDoubleDown = true;
    do {
        std::cout << "Enter your next move: " << std::endl
                  << "(1/h/hit) ........... hit" << std::endl
                  << "(2/s/stand) ....... stand" << std::endl;
        if (_canDoubleDown && canDoubleDown()) 
            std::cout << "(3/d/dd) .... double down" << std::endl;
        std::cout << "Choice: " << std::flush;
        std::cin >> userInput;

        if (_canDoubleDown && canDoubleDown() && (userInput == "3" || userInput == "d" || userInput == "dd")) doubleDown();

        if (userInput == "1" || userInput == "h" || userInput == "hit") { hit = true; inputValid = true; }
        else if (userInput == "2" || userInput == "s" || userInput == "stand") { hit = false; inputValid = true; }
        else { inputValid = false; }

        _canDoubleDown = false;
    } while (!inputValid);
    std::cout << std::endl;

    if (hit) this->hit();
    else this->stand();
}
