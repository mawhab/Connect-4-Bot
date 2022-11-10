#ifndef BOT_H
#define BOT_H
#include "Player.h"
// #include "Board.h"
class Board;

class Bot: public Player{
    public:
        Bot();
        int move(Board *b);
        std::pair<Board*, int> minimize(Board* b);
        std::pair<Board*, int> maximize(Board* b);
};

#endif