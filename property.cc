#include "property.h"

Property::Property(std::string name_in, std::shared_ptr<Player> &owner_in, int cost_in): 
    Tile{name_in}, owner{owner}, cost{cost_in} {}

void Property::perform_turn(std::shared_ptr<Player> landed,
                       std::vector<std::shared_ptr<Player>> players) {
    if (owner) {
        landed->pay_player(owner, calculate_rent());
    }
}