#ifndef _RAILROAD_H_
#define _RAILROAD_H_
#include "property.h"


class Railroad : public Property {
    public:
        Railroad(std::string name_in, std::shared_ptr<Player> owner_in, int cost);
        int calculate_rent() const override;
};

#endif
