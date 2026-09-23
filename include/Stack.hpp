#pragma once

#include <vector>

#include "Card.hpp"

namespace dark {
    class Stack {
    private:
        std::vector<dark::Card>* cardstack = new std::vector<dark::Card>();
        dark::Card* cardTemplateArray = new dark::Card[52];
    public:
        Stack() noexcept;
        void shuffle() noexcept;
        dark::Card draw() noexcept;
        bool canDraw() noexcept;
    };
}
