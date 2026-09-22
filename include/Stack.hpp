#pragma once

#include <vector>

#include "Card.hpp"

namespace dark {
    class Stack {
    private:
        std::vector<dark::Card> cardstack;
        dark::Card* cardTemplateArray;
    public:
        Stack() noexcept;
        void shuffle() noexcept;
    };
}
