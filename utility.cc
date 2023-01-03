#include "utility.h"

Utility::Utility(std::string name_in, int cost): 
    Property{name_in, cost} {}

Utility::~Utility() {}

int Utility::calculate_rent() const {
    if (owner->get_num_utilities() == 1) {
        return owner->get_last_roll() * 4;
    } else if (owner->get_num_utilities() == 2) {
        return owner->get_last_roll() * 10;
    } else {
        return 0;
    }
}