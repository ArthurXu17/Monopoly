#include <iostream>
#include <algorithm>
#include "control.h"

Controller::Controller() {
    char player;
    std::string colour;
    do {
        std::cout<<"Choose a character for the player or enter 'q' to add now more players"<<std::endl;
        std::cin>>player;
        if (player != 'q') {
            std::cout<<"Pick a colour for the player "<<player<<std::endl;
            std::cout<<"Enter in one of the following strings or enter something else for black"<<std::endl;
            std::cout<<"'BROWN', 'LIGHT_BLUE', 'PINK', 'ORANGE', 'RED', 'YELLOW', 'GREEN', 'BLUE'"<<std::endl;
            std::cin>>colour;
            std::transform(colour.begin(), colour.end(),colour.begin(), ::toupper);
            if (colour == "BROWN") {
                colour = BROWN;
            } else if (colour == "LIGHT_BLUE") {
                colour = LIGHT_BLUE;
            } else if (colour == "PINK") {
                colour = PINK;
            } else if (colour == "ORANGE") {
                colour = ORANGE;
            } else if (colour == "RED") {
                colour = RED;
            } else if (colour == "YELLOW") {
                colour = YELLOW;
            } else if (colour == "GREEN") {
                colour = GREEN;
            } else if (colour == "BLUE") {
                colour = BLUE;
            } else {
                colour = RESET;
            }
            players.emplace_back(std::make_shared<Player>(player, colour));
        }
    } while (player != 'q');
    game = std::make_unique<Game>(players);
}

Controller::~Controller() {}

void Controller::play() {
    for (auto p : players) {
        std::cout<<p->get_colour()<<p->get_char()<<std::endl;
    }
    std::cout<<RESET;
    for (auto p : players) {
        int pos;
        std::cout<<"Enter a position: "<<std::endl;
        std::cin>>pos;
        p->move_forward(pos);
    }
    game->print_board();
}