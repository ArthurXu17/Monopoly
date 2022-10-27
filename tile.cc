#include "tile.h"

Tile::Tile(std::string name_in): name{name_in} {}

std::string Tile::get_name() const {
    return name;
}

NothingTile::NothingTile(std::string name_in): Tile{name_in} {}

void NothingTile::perform_turn(std::shared_ptr<Player> landed,
                               std::vector<std::shared_ptr<Player>> players) {
    return;
}

TaxTile::TaxTile(std::string name_in, int amount_in): Tile{name_in}, amount{amount_in} {}

void TaxTile::perform_turn(std::shared_ptr<Player> landed,
                           std::vector<std::shared_ptr<Player>> players) {
    landed->pay_bank(amount);
}