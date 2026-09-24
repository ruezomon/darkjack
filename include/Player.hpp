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
        int budget = 0;
        int currentBet = 0;
        
        dark::Game* game = nullptr;
        bool turn = false;

        void clearCards() noexcept;

    public:
        Player(std::string n, uint16_t budget = 1000) noexcept;
        ~Player();

        void addBudget(uint16_t amount) noexcept;
        bool bet(uint16_t amount) noexcept;
        bool doubleDown() noexcept;

        void play() noexcept;

        bool hit() noexcept;

        void stand() noexcept;

        uint8_t getSum() const noexcept;

        void win() noexcept;
        void bust() noexcept;
        void lose() noexcept;

        bool hasTurn() const noexcept;
        void queryMove() noexcept;
    };
}
