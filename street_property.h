#ifndef _STREET_PROPERTY_H_
#define _STREET_PROPERTY_H_
#include "property.h"

class Street_Property : public Property {
    std::vector<std::unique_ptr<Property>> colour_group;
    int houses = 0;
    int hotels = 0;
    int house_cost;
    std::vector<int> rent_by_houses;
    bool is_monopoly = false;

    public:
        Street_Property(std::string name_in, int cost_in,
                        int house_cost_in, std::vector<int> rent_by_houses_in);
        ~Street_Property();
        int calculate_rent() const override;
        bool can_buy_house() const;
        bool can_buy_hotel() const;
};

#endif
