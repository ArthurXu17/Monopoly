#include <iostream>
#include <memory>
#include "game.h"
#include "control.h"

int main() {
    
    std::unique_ptr<Controller> g = std::make_unique<Controller>();
    g->play();
    std::cout<<std::endl;
}