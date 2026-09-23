#pragma once

#include <vector>

namespace dark {
    class Card;

    class Stack {
    private:
        std::vector<dark::Card>* cardstack = new std::vector<dark::Card>();
        dark::Card* cardTemplateArray;
    public:
        Stack() noexcept;
        void shuffle() noexcept;
        dark::Card draw() noexcept;
        bool canDraw() noexcept;
    };
}
