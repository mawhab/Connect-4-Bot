#include "Bot.h"

Bot::Bot(){
    ;
}

int Bot::move(Board *b){
    Board* target = this->maximize(b);
    int* base_cols = b->get_col_spots();
    int* target_cols = target->get_col_spots();
    for(int i=0;i<b->get_cols();i++){
        if(base_cols[i]!=target_cols[i]) return i;
    }
    return 0;
}

Board* Bot::minimize(Board* b){
    if(b->is_full()) return b;

    Board* min_state = new Board();
    Board* temp_state = nullptr;
    min_state->set_cost(2147483000);

    for(auto x: b->get_neighbors()){
        temp_state = this->maximize(x);
        if(temp_state->get_cost() < min_state->get_cost()){
            min_state = temp_state;
        }
    }
    return min_state;
}

Board* Bot::maximize(Board* b){
    if(b->is_full()) return b;

    Board* temp_state = nullptr;
    Board* max_state = new Board();
    max_state->set_cost(-2147483000);

    for(auto x: b->get_neighbors()){
        temp_state = this->minimize(x);
        if(temp_state->get_cost() > max_state->get_cost()){
            max_state = temp_state;
        }
    }
    return max_state;
}