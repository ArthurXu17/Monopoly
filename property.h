#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "tile.h"
#include "player.h"

class Property : Tile {
    protected:
        std::shared_ptr<Player> owner;
    private:
        int cost;
        bool mortgaged = false;
    public:
        Property(std::string name_in, std::shared_ptr<Player>& owner_in, int cost_in);
        virtual int calculate_rent() const = 0;
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
        bool is_owned() const;
        bool is_mortgaged() const;
};

#endif