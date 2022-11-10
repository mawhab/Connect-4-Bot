#include "Board.h"


int main(){
    Board b; // create board
    // std::vector<Board*> v = b.get_neighbors();
    // for (auto x : v){
    //     print_board(x->board);
    //     std::cout << std::endl;
    // }
    while (!b.is_full()){
        b.move();
        b.print_board();
    }
    std::pair<int,int> scores = b.get_count();

    printf("\n\nPlayer %d wins!\n\n", scores.first>scores.second ? 1 : 2);
    printf("Final score:\nPlayer 1: %d\nPlayer 2: %d\n", scores.first, scores.second);
}

