#ifndef _UTILITY_H_
#define _UTILITY_H_
#include "property.h"


class Utility : public Property {
    public:
        Utility(std::string name_in);
        int calculate_rent() const override;
};

#endif
