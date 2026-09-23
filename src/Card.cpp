#include "Card.hpp"
#include "InitException.hpp"

dark::Card::Card() {
    this->type = 0;
    this->image = 0;
    this->value = 0;
}

dark::Card::Card(uint8_t t, uint8_t i) {
    if (i > 13 || i < 1 || t < 0 || t > 3) throw InitException("Value and/or Type initialized incorrectly");

    this->type = t;
    this->image = i;
    this->value = i > 10 ? 10 : i;
}

uint8_t dark::Card::getValue() const noexcept {
    return value;
}

uint8_t dark::Card::getType() const noexcept {
    return type;
}

std::string dark::Card::getFullName() const noexcept {
    std::string t;
    std::string n;

    switch (this->image) {
        case 1:
            n = "ace";
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            n = std::to_string(this->image);
            break;
        case 11:
            n = "jack";
            break;
        case 12:
            n = "queen";
            break;
        case 13:
            n = "king";
            break;
    }

    switch (this->value) {
        case dark::club:
            t = " of clubs";
            break;
        case dark::diamond:
            t = " of diamonds";
            break;
        case dark::heart:
            t = " of hearts";
            break;
        case dark::spade:
            t = " of spades";
            break;
    }

    return n + t;
}

bool dark::Card::validCard() {
    return value != 0 && image != 0;
}
