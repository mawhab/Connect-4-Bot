#ifndef BOT_H
#define BOT_H
#include "Player.h"

class Bot: public Player{
    public:
        Bot();
        int move(Board *b);
        Board* minimize(Board* b);
        Board* maximize(Board* b);
};

#endif