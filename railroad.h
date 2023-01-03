#ifndef _RAILROAD_H_
#define _RAILROAD_H_
#include "property.h"


class Railroad : public Property {
    public:
        Railroad(std::string name_in, int cost);
        ~Railroad();
        int calculate_rent() const override;
};

#endif
