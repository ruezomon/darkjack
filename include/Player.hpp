#pragma once

#include <stdint.h>
#include <vector>

namespace dark {
    class Card;
    class Game;

    class Player {
    private:
        std::vector<std::vector<dark::Card>> playerCardStacks;
        int budget = 0;
        int currentBet = 0;
        
        dark::Game* game = nullptr;
        bool turn = false;

        void clearCards() noexcept;

    public:
        Player(uint16_t budget = 1000) noexcept;
        ~Player();

        void addBudget(uint16_t amount) noexcept;
        bool bet(uint16_t amount) noexcept;
        bool doubleDown() noexcept;

        void play() noexcept;

        bool hit() noexcept;

        void stand() noexcept;

        bool split(uint8_t deck) noexcept;
        bool splittable(uint8_t deck) const noexcept;

        bool judge(uint8_t stack) const noexcept;
        uint8_t getStackSum(uint8_t stack) const noexcept;

        void win() noexcept;
        void bust() noexcept;

        bool hasTurn() const noexcept;
        void queryMove() noexcept;
    };
}