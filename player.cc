#include <iostream>
#include "player.h"
#include "property.h"
#include "street_property.h"

Player::Player(char ch_in, std::string col_in): ch{ch_in}, colour{col_in} {}

Player::~Player() {}

char Player::get_char() const {
    return ch;
}

std::string Player::get_colour() const {
    return colour;
}

int Player::get_position() const {
    return position;
}

int Player::get_num_railroads() const {
    return num_railroads;
}

int Player::get_num_utilities() const {
    return num_utilities;
}

int Player::get_last_roll() const {
    return last_roll;
}

std::vector<Property *> Player::get_properties() const {
    return owned_property;
}

std::vector<Property *> Player::get_mortgaged_properties() const {
    std::vector<Property *> result;
    for (const auto & propertyPtr: owned_property) {
        if (propertyPtr->is_mortgaged()) {
            result.emplace_back(propertyPtr);
        }
    }
    return result;
}

std::vector<Property *> Player::get_mortgageable_properties() const {
    std::vector<Property *> result;
    for (const auto & propertyPtr: owned_property) {
        if (!propertyPtr->is_mortgaged()) {
            if (propertyPtr->is_railroad() || propertyPtr->is_utility()) {
                result.emplace_back(propertyPtr);
            } else {
                Street_Property *streetPropertyPtr = static_cast<Street_Property *>(propertyPtr);
                if (streetPropertyPtr->get_num_houses() == 0) {
                    result.emplace_back(streetPropertyPtr);
                }
            }
        }
    }
    return result;
}

void Player::print_assets() const {
    std::cout<<"Player: "<<*this<<std::endl;
    std::cout<<"Position: "<<position<<std::endl;
    std::cout<<"Money: $"<<money<<std::endl;
    std::cout<<"Unmortgaged Properties:"<<std::endl;
    for (const auto & propertyPtr: owned_property) {
        if (!propertyPtr->is_mortgaged()) {
            std::cout<<propertyPtr->get_name()<<std::endl;
        }
    }
    std::cout<<"Mortgaged Properties:"<<std::endl;
    for (const auto & propertyPtr: owned_property) {
        if (propertyPtr->is_mortgaged()) {
            std::cout<<propertyPtr->get_name()<<std::endl;
        }
    }
    std::cout<<"--------------------"<<std::endl;
}

void Player::earn_money(int amount) {
    money+=amount;
}

void Player::pay_bank(int amount) {
    money-=amount;
}

void Player::move_forward(int amount) {
    if (position + amount >= 40) {
        std::cout<<"Player "<<*this<<" passed GO. Collect $200!"<<std::endl;
        earn_money(200);
    }
    last_roll = amount;
    position = (position + amount) % 40;
}

void Player::pay_player(std::shared_ptr<Player> &receiver, int amount) {
    receiver->earn_money(amount);
    money-=amount;
}

void Player::add_property(Property* property) {
    owned_property.emplace_back(property);
    if (property->is_railroad()) {
        num_railroads++;
    } else if (property->is_utility()) {
        num_utilities++;
    }
}

void Player::send_to_jail() {
    in_jail = true;
    position = 30;
}

std::ostream &operator<<(std::ostream &out, const Player p) {
    out<<p.get_colour()<<p.get_char()<<RESET;
    return out;
}
