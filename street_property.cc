#include "street_property.h"

Street_Property::Street_Property(std::string name_in, int cost_in,
                                 int house_cost_in, std::vector<int> rent_by_houses_in):
    Property{name_in, cost_in}, house_cost{house_cost_in}, rent_by_houses{rent_by_houses_in} {}

Street_Property::~Street_Property() {}

void Street_Property::add_colour_group_member(Street_Property * other) {
    colour_group.emplace_back(other);
}

int Street_Property::calculate_rent(std::shared_ptr<Player> landed) const {
    if (houses == 0 && is_monopoly()) {
        return 2 * rent_by_houses[houses];
    } else {
        return rent_by_houses[houses];
    }
}

bool Street_Property::is_monopoly() const {
    for (const auto & propertyPtr : colour_group) {
        if (propertyPtr->owner != this->owner) {
            return false;
        }
    }
    return true;
}

bool Street_Property::is_railroad() const {
    return false;
}

bool Street_Property::is_utility() const {
    return false;
}

int Street_Property::get_house_cost() const {
    return house_cost;
}

int Street_Property::get_num_houses() const {
    return houses;
}

bool Street_Property::shared_building_check() const {
    if (!is_monopoly()) {
        return false;
    } else {
        for (const auto & propertyPtr : colour_group) {
            if (propertyPtr->get_num_houses() < houses) {
                return false;
            }
        }
        return true;
    }
}

bool Street_Property::can_buy_house() const {
    return (shared_building_check() && houses < 4);
}

bool Street_Property::can_buy_hotel() const {
    return (shared_building_check() && houses == 4);
}

void Street_Property::build_house() {
    houses++;
}