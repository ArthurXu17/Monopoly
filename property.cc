#include "property.h"
#include <iostream>

Property::Property(std::string name_in, int cost_in): 
    Tile{name_in}, cost{cost_in} {
        owner = nullptr;
    }

Property::~Property() {}

void Property::perform_turn(std::shared_ptr<Player> landed,
                       std::vector<std::shared_ptr<Player>> players) {
    if (owner) {
        if (owner == landed) {
            std::cout<<"Player "<<*landed<<" landed on their property "<<name<<std::endl;
        } else {
            std::cout<<"Player "<<*landed<<" landed on "<<*owner<<"'s property: "<<name<<std::endl;
            int rent = calculate_rent(landed);
            std::cout<<*landed<<" pays "<<*owner<<" $"<<rent<<" in rent"<<std::endl;
            landed->pay_player(owner, rent);
        }
    } else {
        std::cout<<"Player "<<*landed<<" landed on the unowned property "<<name<<std::endl;
        std::cout<<"Would you like to buy or auction "<<name<<"? Enter 'b' or 'a'"<<std::endl;
        char input;
        std::cin>>input;
        if (input == 'a') {

        } else {
            owner = landed;
            owner->pay_bank(cost);
            owner->add_property(this);
        }
    }
}

bool Property::is_owned() const {
    return !(owner == nullptr);
}

bool Property::is_mortgaged() const {
    return mortgaged;
}