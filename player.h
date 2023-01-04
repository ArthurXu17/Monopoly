#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <vector>
#include <memory>
#include "constants.h"

class Property;

class Player {
    char ch;
    std::string colour;
    int position = 0;
    int money = 1500;
    int last_roll = 0; // used for utilities
    int num_railroads = 0;
    int num_utilities = 0;
    int jail_turns = 0;
    bool in_jail = false;
    int num_get_out_of_jail = 0;
    std::vector<Property *> owned_property;
    public:
        Player(char ch_in, std::string col_in);
        ~Player();
        // getters
        char get_char() const;
        std::string get_colour() const;
        int get_position() const;
        int get_num_railroads() const;
        int get_num_utilities() const;
        int get_last_roll() const;
        void print_assets() const;
        // modifiers from game
        void earn_money(int amount);
        void pay_bank(int amount);
        void pay_player(std::shared_ptr<Player> &receiver, int amount);
        void move_forward(int steps);
        void add_property(Property * property);
};

std::ostream &operator<<(std::ostream &out, const Player p);

#endif