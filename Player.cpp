#include "Player.h"


Player::Player(){
    this->count = 0;
    this->row = new int[6];
    this->col = new int[7];
    this->diag_p = new int[6];
    this->diag_n = new int[6];
}

int Player::inc_row(int i){
    return ++this->row[i];
}

int Player::inc_col(int i){
    return ++this->col[i];
}

int Player::inc_diag_n(int i){
    return ++this->diag_n[i];
}

int Player::inc_diag_p(int i){
    return ++this->diag_p[i];
}

void Player::clr_col(int i){
    this->col[i] = 0;
}

void Player::clr_row(int i){
    this->row[i] = 0;
}

void Player::clr_diag_n(int i){
    this->diag_n[i] = 0;
}

void Player::clr_diag_p(int i){
    this->diag_p[i] = 0;
}

int Player::move() {
    return 0;
}