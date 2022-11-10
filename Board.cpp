#include "Board.h"

Board::Board(int rows, int cols){
    this->rows = rows;
    this->cols = cols;
    this->board = new int*[this->rows];
    for(int i=0;i<this->rows;i++){
        this->board[i] = new int[this->cols];
    }

    this->col_spots = new int[this->cols];
    this->turn = false;
    this->depth = 0;
    this->cost = 0;
    this->h = Human();
    this->b = Bot();
}

Board::Board(){
    this->rows = 6;
    this->cols = 7;
    this->board = new int*[this->rows];
    for(int i=0;i<this->rows;i++){
        this->board[i] = new int[this->cols];
    }

    this->col_spots = new int[this->cols] {this->rows-1, this->rows-1,
                                           this->rows-1, this->rows-1,
                                           this->rows-1, this->rows-1,
                                           this->rows-1};
    this->turn = false;
    this->depth = 0;
    this->cost = 0;
    this->h = Human();
    this->b = Bot();
}

Board::Board(Board* cpy){
    this->rows = cpy->rows;
    this->cols = cpy->cols;
    this->col_spots = new int[this->cols];
    this->board = new int*[this->rows];
    for(int i=0;i<this->rows;i++){
        this->board[i] = new int[this->cols];
        for(int j=0;j<this->cols;j++){
            this->board[i][j] = cpy->board[i][j];
        }
    }
    for(int j=0;j<this->cols;j++){
        this->col_spots[j] = cpy->col_spots[j];
    }

    this->turn = cpy->turn;
    this->depth = cpy->depth+1;
    this->cost = cpy->cost;
}

void Board::move(){
    int move;
    if(this->turn){
        do{
            move = this->h.move()-1;
        }while(!this->is_allowed(move));
        this->move(move);
    }else{
        do{
            move = this->b.move(this)-1;
        }while(!this->is_allowed(move));
        this->move(move);
    }
}

void Board::move(int col){
    // set the board location at [last free row in col][col] to current turns player
    // and increment (last free row in col)
    this->board[this->col_spots[col]--][col] = turn+1;
    this->turn = !this->turn;
}

std::vector<Board*> Board::get_neighbors(){
    std::vector<Board*> neighbors;
    
    Board* temp = nullptr;
    for(int i=0;i<this->cols;i++){
        if(col_spots[i]>=0){
            temp = new Board(this);
            temp->move(i);
            neighbors.push_back(temp);
        }
    }
    delete temp;

    return neighbors;
}

bool Board::is_full(){
    for(int i=0;i<this->cols;i++){
        if(this->col_spots[i]>=0) return false;
    }
    return true;
}

bool Board::get_turn(){
    return this->turn;
}

int ** Board::get_board(){
    return this->board;
}

bool Board::is_allowed(int move){
    return (this->col_spots[move]>=0);
}

int Board::get_depth(){
    return this->depth;
}

int Board::get_cost(){
    return this->cost;
}

void Board::set_cost(int c){
    this->cost = c;
}

int Board::get_cols(){
    return this->cols;
}

int* Board::get_col_spots(){
    return this->col_spots;
}

std::pair<int,int> Board::get_count(){
    int count[] = {0,0};
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            char dp_i = j - i + 2;
            char dn_i = j + i - 3;
            char p = board[i][j]-1;
            if(p==0){
                if(h.inc_row(i)==4) {
                    count[p]++;
                    h.clr_row(i);
                }
                if(h.inc_col(j)==4){
                    count[p]++;
                    h.clr_col(j);
                }
                if(dp_i>=0 && dp_i<6 && h.inc_diag_p(dp_i)==4){
                    count[p]++;
                    h.clr_diag_p(dp_i);
                }
                if(dn_i>=0 && dn_i<6 && h.inc_diag_n(dn_i)==4){
                    count[p]++;
                    h.inc_diag_n(dn_i);
                }
            }else{
                h.clr_row(i);
                h.clr_col(j);
                if(dp_i>=0 && dp_i<6){
                    h.clr_diag_p(dp_i);
                }
                if(dn_i>=0 && dn_i<6){
                    h.clr_diag_n(dn_i);
                }
            }
            if(p==1){
                if(b.inc_row(i)==4) {
                    count[p]++;
                    b.clr_row(i);
                }
                if(b.inc_col(j)==4){
                    count[p]++;
                    b.clr_col(j);
                }
                if(dp_i>=0 && dp_i<6 && b.inc_diag_p(dp_i)==4){
                    count[p]++;
                    b.clr_diag_p(dp_i);
                }
                if(dn_i>=0 && dn_i<6 && b.inc_diag_n(dn_i)==4){
                    count[p]++;
                    b.inc_diag_n(dn_i);
                }
            }else{
                b.clr_row(i);
                b.clr_col(j);
                if(dp_i>=0 && dp_i<6){
                    b.clr_diag_p(dp_i);
                }
                if(dn_i>=0 && dn_i<6){
                    b.clr_diag_n(dn_i);
                }
            }
        }
    }

    std::pair<int,int> res(count[0], count[1]);
}
