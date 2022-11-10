#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Bot.h"
#include "Human.h"

class Board{
    private:
        int **board;
        bool turn;
        int rows;
        int cols;
        int *col_spots;
        int depth;
        int cost;
        Human h;
        Bot b;

    public:
        Board(int rows, int cols);
        Board();
        Board(Board* cpy);
        void move();
        void move(int col);
        std::vector<Board*> get_neighbors();
        bool is_full();
        bool get_turn();
        bool is_allowed(int move);
        int **get_board();
        int get_depth();
        int get_cost();
        void set_cost(int c);
        int get_cols();
        int* get_col_spots();
        std::pair<int,int> get_count();
        void print_board();
};
#endif