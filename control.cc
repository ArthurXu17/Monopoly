#include <iostream>
#include "control.h"

Controller::Controller() {
    // rng initialization
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    gen = std::mt19937(seed);
    rng = std::default_random_engine(seed);
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

std::pair<int,int> Controller::roll_dice(bool loaded, std::mt19937& game_gen) const {
    std::pair<int,int> result;
    for (int i = 0; i <= 1; i++) {
        if (loaded) {
            int min = 1, max = 6;
            int roll = 0;
            while (true) {
                std::cout << "Input a roll between " << min << " and " << max << ".\n> "; // prompt for roll
                std::cin >> roll;
                if (roll < min || roll > max) { // not within range
                    std::cout << "Invalid roll." << std::endl;
                }
                else break;
            }
            if (i == 0) {
                result.first = roll;
            } else {
                result.second = roll;
            }
        } else {
            std::uniform_int_distribution<> distrib(1, 6);
            int roll = distrib(game_gen);
            if (i == 0) {
                result.first = roll;
            } else {
                result.second = roll;
            }
        }
    }
    return result;
}

void Controller::play() {
    for (auto p : players) {
        std::cout<<p->get_colour()<<p->get_char()<<std::endl;
    }
    std::cout<<RESET;
    game->print_board();
}