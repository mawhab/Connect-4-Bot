#include "Human.h"

Human::Human(){
    ;
}


int Human::move(){
    int col;
    std::cout << "enter col: " << std::endl;
    std::cin >> col;
    return col;
}