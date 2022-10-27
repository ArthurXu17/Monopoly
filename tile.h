#ifndef _TILE_H_
#define _TILE_H_
#include <memory>
#include <vector>
#include "player.h"

class Tile {
    std::string name;
    public:
        Tile(std::string name_in);
        std::string get_name() const;
        virtual void perform_turn(std::shared_ptr<Player> landed,
                                  std::vector<std::shared_ptr<Player>> players) = 0;
};

// class for Free Parking, Just Visiting Jail and Go
class NothingTile : Tile{
    public:
        NothingTile(std::string name_in);
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
};

class TaxTile : Tile {
    int amount;
    public:
        TaxTile(std::string name_in, int amount_in);
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
};

#endif
