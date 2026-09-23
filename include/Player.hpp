#pragma once

#include <vector>

#include "Card.hpp"
#include "Game.hpp"

namespace dark {
    class Player {
    private:
        std::vector<std::vector<dark::Card>> playerCardStacks;
        int budget = 0;
        int currentBet = 0;
        dark::Game* game;

    public:
        Player() noexcept;

        bool doubleDown() noexcept;

        bool hit() noexcept;

        void stand() noexcept;

        bool split(uint8_t deck) noexcept;
        bool splittable(uint8_t deck) const noexcept;

        bool judge(uint8_t stack) noexcept;

    };
}