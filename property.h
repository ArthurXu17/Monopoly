#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include "player.h"

class Property {
    std::shared_ptr<Player> owner;
    int cost;
    bool mortgaged;
    public:
        virtual int calculate_rent() const = 0;
        bool is_owned() const;
        bool is_mortgaged() const;
};

#endif