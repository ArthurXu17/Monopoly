#ifndef _TILE_H_
#define _TILE_H_
#include <memory>
#include <vector>
#include "player.h"

class Tile {
    protected:
        std::string name;
    public:
        Tile(std::string name_in);
        virtual ~Tile();
        std::string get_name() const;
        virtual void perform_turn(std::shared_ptr<Player> landed,
                                  std::vector<std::shared_ptr<Player>> players) = 0;
};

// class for Free Parking, Just Visiting Jail and Go
class NothingTile : public Tile {
    public:
        ~NothingTile();
        NothingTile(std::string name_in);
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
};

class TaxTile : public Tile {
    int amount;
    public:
        ~TaxTile();
        TaxTile(std::string name_in, int amount_in);
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
};

#endif
