#pragma once

#include <thread>
#include <vector>

namespace dark {
    class Player;
    class Stack;
    class Card;

    class Game {
    private:
        dark::Stack* stack = nullptr;
        bool running;
        
        dark::Player* player = nullptr;
        std::thread* playerWatcher = nullptr;

        // will not implement splitting for dealer
        std::vector<dark::Card> dealerStack;

        void drawCardsDealer(uint8_t n = 1) noexcept;
        uint8_t getDealerSum() const noexcept;

    public:
        Game(dark::Player* p);
        ~Game();

        void start() noexcept;
        void reshuffle() noexcept;
        void finishGame() noexcept;

        dark::Card drawCard() noexcept;

    }; 
}
