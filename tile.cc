#include "tile.h"
#include <iostream>

Tile::Tile(std::string name_in): name{name_in} {}

Tile::~Tile() {}

std::string Tile::get_name() const {
    return name;
}

NothingTile::NothingTile(std::string name_in): Tile{name_in} {}

NothingTile::~NothingTile() {}

void NothingTile::perform_turn(std::shared_ptr<Player> landed,
                               std::vector<std::shared_ptr<Player>> players) {
    std::cout<<*landed<<" landed on "<<name<<". Nothing Happens."<<std::endl;;
    return;
}

TaxTile::TaxTile(std::string name_in, int amount_in): Tile{name_in}, amount{amount_in} {}

TaxTile::~TaxTile() {}

void TaxTile::perform_turn(std::shared_ptr<Player> landed,
                           std::vector<std::shared_ptr<Player>> players) {
    std::cout<<*landed<<" landed on "<<name<<". They pay the bank $"<<amount<<"."<<std::endl;
    landed->pay_bank(amount);
}