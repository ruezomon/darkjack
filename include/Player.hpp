#pragma once

#include <stdint.h>
#include <vector>

namespace dark {
    class Card;
    class Game;

    class Player {
    private:

        std::string name;
        
        std::vector<dark::Card> playerCardStack;
        uint16_t budget = 0;
        uint16_t currentBet = 0;
        
        dark::Game* game = nullptr;

        void play() noexcept;
        void clearCards() noexcept;

        void hit() noexcept;
        void stand() noexcept;
        bool doubleDown() noexcept;

        void printCards() const noexcept;

    public:
        Player(std::string n, uint16_t budget = 1000) noexcept;
        ~Player();

        void addBudget(uint16_t amount) noexcept;
        bool bet(uint16_t amount) noexcept;

        uint8_t getSum() const noexcept;
        uint16_t getBudget() const noexcept;

        bool canDoubleDown() const noexcept;

        void giveCard(bool verbal = true) noexcept;

        void win() noexcept;
        void bust() noexcept;
        void push() noexcept;
        void lose() noexcept;

        void queryMove() noexcept;
    };
}
