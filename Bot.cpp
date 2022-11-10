#include "Bot.h"

Bot::Bot(){
    ;
}

int Bot::move(Board *b){
    Board* target = this->maximize(b).first;
    int* base_cols = b->get_col_spots();
    int* target_cols = target->get_col_spots();
    for(int i=0;i<b->get_cols();i++){
        if(base_cols[i]!=target_cols[i]) return i;
    }
    return 0;
}

std::pair<Board*, int> Bot::minimize(Board* b){
    if(b->is_full()) return std::pair<Board*, int>(nullptr, b->get_count().first);

    std::pair<Board*, int> min_found(nullptr, 2147483000);
    std::pair<Board*, int> temp_state;

    for(auto x: b->get_neighbors()){
        temp_state = this->maximize(x);
        if(temp_state.second < min_found.second){
            min_found = temp_state;
        }
    }
    return min_found;
}

std::pair<Board*, int> Bot::maximize(Board* b){
    if(b->is_full()) return std::pair<Board*, int>(nullptr, b->get_count().first);

    std::pair<Board*, int> max_found(nullptr, -2147483000);
    std::pair<Board*, int> temp_state;

    for(auto x: b->get_neighbors()){
        temp_state = this->minimize(x);
        if(temp_state.second > max_found.second){
            max_found = temp_state;
        }
    }
    return max_found;
}