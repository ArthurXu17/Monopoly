#include "street_property.h"

Street_Property::Street_Property(std::string name_in, std::shared_ptr<Player> owner_in, int cost_in,
                                 int house_cost_in, std::vector<int> rent_by_houses_in):
    Property{name_in, owner_in, cost_in}, house_cost{house_cost_in}, rent_by_houses{rent_by_houses_in} {}

int Street_Property::calculate_rent() const {
    if (houses == 0 && is_monopoly) {
        return 2 * rent_by_houses[houses];
    } else {
        return rent_by_houses[houses];
    }
}