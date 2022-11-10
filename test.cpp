#include "Bot.h"
#include "Human.h"

void print_board(int **b){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    Board b;
    // std::vector<Board*> v = b.get_neighbors();
    // for (auto x : v){
    //     print_board(x->board);
    //     std::cout << std::endl;
    // }
    Human player;
    Human ai;
    int move;
    while (!b.is_full()){
        b.move();
        print_board(b.get_board());
    }
    
}
