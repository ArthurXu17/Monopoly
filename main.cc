#include <iostream>
#include <memory>
#include "game.h"

int main() {
    
    std::unique_ptr<Game> g = std::make_unique<Game>();
    g->print_board();
    std::cout<<std::endl;
}