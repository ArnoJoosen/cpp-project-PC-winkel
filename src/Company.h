//
// Created by arno on 10/25/23.
//

#ifndef PC_WINKLE_COMPANY_H
#define PC_WINKLE_COMPANY_H
#include "Customer.h"

class Company : public Customer {
public:

private:
    void calculateReduction();

    int var;
    int reduction;
    int yearlyBey;
};


#endif //PC_WINKLE_COMPANY_H
