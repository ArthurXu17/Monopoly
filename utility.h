#ifndef _UTILITY_H_
#define _UTILITY_H_
#include "property.h"


class Utility : public Property {
    public:
        Utility(std::string name_in, int cost);
        ~Utility();
        int calculate_rent(std::shared_ptr<Player> landed) const override;
        bool is_railroad() const override;
        bool is_utility() const override;
};

#endif
