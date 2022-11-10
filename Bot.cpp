#include "Bot.h"
#include "Board.h"

Bot::Bot(int depth) : MAX_DEPTH(depth){
    ;
}

Bot::Bot() : MAX_DEPTH(20){
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
    if(b->is_full()) return std::pair<Board*, int>(b, b->get_count().first);
    if(b->get_depth()>=this->MAX_DEPTH) return Bot::evaluate(b);

    std::pair<Board*, int> min_found(nullptr, 2147483000);
    std::pair<Board*, int> temp_state;

    for(auto x: b->get_neighbors()){
        temp_state = this->maximize(x);
        if(temp_state.second < min_found.second){
            min_found.second = temp_state.second;
            min_found.first = x;
        }
    }
    return min_found;
}

std::pair<Board*, int> Bot::maximize(Board* b){
    if(b->is_full()) return std::pair<Board*, int>(b, b->get_count().first);
    if(b->get_depth()>=this->MAX_DEPTH) return Bot::evaluate(b);

    std::pair<Board*, int> max_found(nullptr, -2147483000);
    std::pair<Board*, int> temp_state;

    for(auto x: b->get_neighbors()){
        temp_state = this->minimize(x);
        if(temp_state.second > max_found.second){
            max_found.second = temp_state.second;
            max_found.first = x;
        }
    }
    return max_found;
}

std::pair<Board*, int> Bot::evaluate(Board* b){
    return std::pair<Board*, int>(b, 0);
}
