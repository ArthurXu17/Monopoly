#include "street_property.h"

Street_Property::Street_Property(std::string name_in, int cost_in,
                                 int house_cost_in, std::vector<int> rent_by_houses_in):
    Property{name_in, cost_in}, house_cost{house_cost_in}, rent_by_houses{rent_by_houses_in} {}

Street_Property::~Street_Property() {}

int Street_Property::calculate_rent(std::shared_ptr<Player> landed) const {
    if (houses == 0 && is_monopoly) {
        return 2 * rent_by_houses[houses];
    } else {
        return rent_by_houses[houses];
    }
}

bool Street_Property::is_railroad() const {
    return false;
}

bool Street_Property::is_utility() const {
    return false;
}

int Street_Property::get_num_houses() const {
    return houses;
}