#pragma once

#include <stdint.h>
#include <string>

namespace dark {
    enum CARDTYPES {spade, heart, club, diamond};

    class Card {
    private:
        uint8_t value;
        uint8_t image;
        uint8_t type;

        bool validCard();

    public:
        Card();
        Card(uint8_t t, uint8_t v);
        uint8_t getValue() const noexcept;
        uint8_t getType() const noexcept;
        std::string getFullName() const noexcept;
    };
}
