#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <vector>
#include <memory>

class Property;

class Player {
    int position;
    int money;
    int num_railroads = 0;
    int num_utilities = 0;
    int jail_turns = 0;
    bool in_jail = false;
    int num_get_out_of_jail = 0;
    std::vector<std::unique_ptr<Property>> owned_property;
    public:
        void earn_money(int amount);
        void pay_bank(int amount);
        void pay_player(std::unique_ptr<Player> receiver, int amount);
};

#endif