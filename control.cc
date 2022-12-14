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

Property * Controller::select_property(std::vector<Property *> list_of_properties, std::string action) const {
    std::cout<<"Select a property to "<<action<<"."<<std::endl;
    for (std::size_t i = 0; i < list_of_properties.size(); i++) {
        std::cout<<i<<" - "<<list_of_properties[i]->get_name()<<std::endl;
    }
    std::size_t index;
    while (true) {
        std::cin>>index;
        if (0 <= index && index < list_of_properties.size()) {
            break;
        } else {
            std::cout<<"The input was not in the range of 0-"<<list_of_properties.size()<<std::endl;
            std::cout<<"Choose a number in the valid range."<<std::endl;
        }
    }
    return list_of_properties[index];
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
            } else if (turn_cmd == "build-house") {
                std::vector<Property *> house_properties = p->build_house_properties();
                if (house_properties.size() == 0) {
                    std::cout<<"There are no properties to build a house on."<<std::endl;
                } else {
                    Property *property_to_build = select_property(house_properties, "build a house on");
                    Street_Property *street_property = static_cast<Street_Property *>(property_to_build);
                    int house_cost = street_property->get_house_cost();
                    p->pay_bank(house_cost);
                    street_property->build_house();
                    std::cout<<"Player "<<*p<<" paid the bank $"<<house_cost<<" to buy a house on "<<street_property->get_name()<<"."<<std::endl;
                }
            } else if (turn_cmd == "build-hotel") {
                std::vector<Property *> hotel_properties = p->build_hotel_properties();
                if (hotel_properties.size() == 0) {
                    std::cout<<"There are no properties to build a hotel on."<<std::endl;
                } else {
                    Property *property_to_build = select_property(hotel_properties, "build a hotel on");
                    Street_Property *street_property = static_cast<Street_Property *>(property_to_build);
                    int house_cost = street_property->get_house_cost();
                    p->pay_bank(house_cost);
                    street_property->build_house(); // building hotel calls build_house function
                    std::cout<<"Player "<<*p<<" paid the bank $"<<house_cost<<" to buy a hotel on "<<street_property->get_name()<<"."<<std::endl;
                }
            } else if (turn_cmd == "mortgage") {
                std::vector<Property *> mortgageable_properties = p->get_mortgageable_properties();
                if (mortgageable_properties.size() == 0) {
                    std::cout<<"There are no properties available to mortgage"<<std::endl;
                } else {
                    Property *property_to_mortgage = select_property(mortgageable_properties, "mortgage");
                    int money_gain = property_to_mortgage->get_cost() / 2;
                    property_to_mortgage->mortgage_property();
                    p->earn_money(money_gain);
                    std::cout<<"Successfully Mortgaged "<<property_to_mortgage->get_name()<<". "<<*p<<" received $"<<money_gain<<"."<<std::endl;
                }
            } else if (turn_cmd == "unmortgage") {
                std::vector<Property *> mortgaged_properties = p->get_mortgaged_properties();
                if (mortgaged_properties.size() == 0) {
                    std::cout<<"There are no properties available to unmortgage"<<std::endl;
                } else {
                    Property *property_to_unmortgage = select_property(mortgaged_properties, "unmortgage");
                    int cost = 3 * property_to_unmortgage->get_cost() / 5;
                    property_to_unmortgage->unmortgage_property();
                    p->pay_bank(cost);
                    std::cout<<"Successfully Unmortgaged "<<property_to_unmortgage->get_name()<<". "<<*p<<" payed bank $"<<cost<<"."<<std::endl;
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