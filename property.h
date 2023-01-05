#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "tile.h"
#include "player.h"

class Property : public Tile {
    protected:
        std::shared_ptr<Player> owner;
    private:
        int cost;
        bool mortgaged = false;
    public:
        Property(std::string name_in, int cost_in);
        virtual ~Property();
        virtual int calculate_rent(std::shared_ptr<Player> landed) const = 0;
        virtual bool is_railroad() const = 0;
        virtual bool is_utility() const = 0;
        virtual bool can_buy_house() const = 0;
        virtual bool can_buy_hotel() const = 0;
        void perform_turn(std::shared_ptr<Player> landed,
                          std::vector<std::shared_ptr<Player>> players) override;
        int get_cost() const;
        bool is_owned() const;
        bool is_mortgaged() const;
        void mortgage_property();
        void unmortgage_property();
};

#endif