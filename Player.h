#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Board.h"

class Player{
    protected:
        int count;
        int *col;
        int *row;
        int *diag_p;
        int *diag_n;

    public:
        Player();
        virtual int move();
        int inc_row(int i);
        int inc_col(int i);
        int inc_diag_p(int i);
        int inc_diag_n(int i);

        void clr_row(int i);
        void clr_col(int i);
        void clr_diag_p(int i);
        void clr_diag_n(int i);
};

#endif