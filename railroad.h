#ifndef _RAILROAD_H_
#define _RAILROAD_H_
#include "property.h"


class Railroad : public Property {
    public:
        Railroad(std::string name_in, int cost);
        ~Railroad();
        int calculate_rent(std::shared_ptr<Player> landed) const override;
        bool is_railroad() const override;
        bool is_utility() const override;
        bool can_buy_house() const override;
        bool can_buy_hotel() const override;
};

#endif
