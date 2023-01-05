#include "utility.h"

Utility::Utility(std::string name_in, int cost): 
    Property{name_in, cost} {}

Utility::~Utility() {}

int Utility::calculate_rent(std::shared_ptr<Player> landed) const {
    if (owner->get_num_utilities() == 1) {
        return landed->get_last_roll() * 4;
    } else if (owner->get_num_utilities() == 2) {
        return landed->get_last_roll() * 10;
    } else {
        return 0;
    }
}

bool Utility::is_railroad() const {
    return false;
}

bool Utility::is_utility() const {
    return true;
}