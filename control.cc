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

std::pair<int,int> Controller::roll_dice() {
    std::pair<int,int> result;
    std::uniform_int_distribution<> distrib(1, 6);
    for (int i = 0; i <= 1; i++) {
        if (loadedDice) {
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
            int roll = distrib(gen);
            if (i == 0) {
                result.first = roll;
            } else {
                result.second = roll;
            }
        }
    }
    return result;
}

std::pair<int,int> Controller::roll_dice_io() {
    while (true) {
        std::cout << "Current dice are " << ((loadedDice) ? "load" : "fair") << ". "
                  << "Enter \"load\" to change current dice to loaded dice, \"fair\" to change current dice to fair dice, or \"roll\" to roll the current dice.\n> ";
        std::string cmd;
        std::cin >> cmd;
        std::cout << std::endl;
        if (cmd == "fair") {  // fair dice
            loadedDice = false;
        } else if (cmd == "load") {  // loaded dice
            loadedDice = true;
        } else if (cmd == "roll")
            break;
    }
    return roll_dice();
}

void Controller::play() {
    while (true) {
        std::shared_ptr<Player> p = players[turn % players.size()];
        std::string turn_cmd;
        bool rolled_dice = false;
        int numDoubles = 0;
        bool end_game = false;
        while (turn_cmd != "next") {
            std::cout << "Player "<<*p<<"'s turn. Please enter a command (enter \"help\" to show valid commands).\n> ";
            std::cin >> turn_cmd;
            if (turn_cmd == "board") {  // prints current board
                game->print_board();
            } else if (turn_cmd == "roll") {
                if (rolled_dice) {
                    std::cout<<"Dice has already been rolled this turn"<<std::endl;
                } else {
                    std::pair<int, int> diceRoll = roll_dice_io();
                    int diceRollNum = diceRoll.first + diceRoll.second;
                    if (diceRoll.first == diceRoll.second) {
                        std::cout<<"You rolled double "<<diceRoll.first<<"s. You may roll again this turn."<<std::endl;
                        numDoubles++;
                        if (numDoubles >= 3) {
                            std::cout<<"You rolled 3 doubles in a row. Go To Jail."<<std::endl;
                            p->send_to_jail();
                            rolled_dice = true;
                        } else {
                            p->move_forward(diceRollNum);
                            game->playerLandOnTile(p);
                        }
                    } else {
                        std::cout<<"You rolled "<<diceRoll.first<<" and "<<diceRoll.second<<"."<<std::endl;
                        rolled_dice = true;
                        p->move_forward(diceRollNum);
                        game->playerLandOnTile(p);
                    }
                } 
            } else if (turn_cmd == "mortgage") {
                std::string property_name;
                std::cin.ignore();
                std::getline(std::cin, property_name);
                std::vector<Property *> mortgageable_properties = p->get_mortgageable_properties();
                Property *property_to_mortgage = nullptr;
                for (auto & propertyPtr : mortgageable_properties) {
                    if (propertyPtr->get_name() == property_name) {
                        property_to_mortgage = propertyPtr;
                    }
                }
                if (property_to_mortgage) {
                    int money_gain = property_to_mortgage->get_cost() / 2;
                    property_to_mortgage->mortgage_property();
                    p->earn_money(money_gain);
                    std::cout<<"Successfully Mortgaged "<<property_name<<". "<<*p<<" received $"<<money_gain<<"."<<std::endl;
                } else {
                    std::cout<<property_name<<" is not a valid mortgageable property"<<std::endl;
                }
            } else if (turn_cmd == "unmortgage") {
                std::string property_name;
                std::cin.ignore();
                std::getline(std::cin, property_name);
                std::vector<Property *> mortgaged_properties = p->get_mortgaged_properties();
                Property *property_to_unmortgage = nullptr;
                for (auto & propertyPtr : mortgaged_properties) {
                    if (propertyPtr->get_name() == property_name) {
                        property_to_unmortgage = propertyPtr;
                    }
                }
                if (property_to_unmortgage) {
                    int cost = 3 * property_to_unmortgage->get_cost() / 5;
                    property_to_unmortgage->unmortgage_property();
                    p->pay_bank(cost);
                    std::cout<<"Successfully Unmortgaged "<<property_name<<". "<<*p<<" payed bank $"<<cost<<"."<<std::endl;
                } else {
                    std::cout<<property_name<<" is not a valid property to unmortgage"<<std::endl;
                }
            } else if (turn_cmd == "assets") {
                p->print_assets();
            } else if (turn_cmd == "all-assets") {
                for (auto & player : players) {
                    player->print_assets();
                }
            } else if (turn_cmd == "next") {
                if (!rolled_dice) {
                    std::cout<<"You have not finished your rolls this turn"<<std::endl;
                    turn_cmd = ""; // change turn_cmd to stay in same turn
                } else {
                    continue;
                }
            } else if (turn_cmd == "quit") {
                end_game = true;
                break;
            } else {  // invalid command
                std::cout << "Invalid command." << std::endl;
            }
        }
        if (end_game) {
            break;
        }
        turn = (turn + 1) % players.size();
    }
}