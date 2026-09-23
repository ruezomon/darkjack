#pragma once

#include <thread>
#include <vector>

namespace dark {
    class Player;
    class Stack;
    class Card;

    class Game {
    private:
        dark::Stack* stack;
        bool running;
        
        dark::Player* player;
        std::thread* playerWatcher;

        // will not implement splitting for dealer
        std::vector<dark::Card> dealerStack;

        void drawCardDealer();
        void getDealerSum();

    public:
        Game(dark::Player* p);

        void start();
        void reshuffle();

    }; 
}
