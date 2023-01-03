#include "railroad.h"

Railroad::Railroad(std::string name_in, int cost):
    Property{name_in, cost} {}

Railroad::~Railroad() {}

int Railroad::calculate_rent() const {
    if (owner->get_num_railroads() == 1) {
        return 25;
    } else if (owner->get_num_railroads() == 2) {
        return 50;
    } else if (owner->get_num_railroads() == 3) {
        return 100;
    } else if (owner->get_num_railroads() == 4) {
        return 200;
    } else {
        return 0;
    }
}