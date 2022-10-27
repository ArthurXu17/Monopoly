#include <iostream>
#include "player.h"

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

void Player::earn_money(int amount) {
    money+=amount;
}

void Player::pay_bank(int amount) {
    money-=amount;
}

void Player::move_forward(int amount) {
    if (position + amount >= 40) {
        earn_money(200);
    }
    position = (position + amount) % 40;
}

void Player::pay_player(std::shared_ptr<Player> &receiver, int amount) {
    receiver->earn_money(amount);
    money-=amount;
}

std::ostream &operator<<(std::ostream &out, const Player p) {
    out<<p.get_colour()<<p.get_char()<<RESET;
    return out;
}
