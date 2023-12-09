//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPANY_H
#define PC_WINKLE_COMPANY_H
#include "Customer.h"
#include <memory>

class Company : public Customer {
public:
    Company();
    Company(Name_t name, Address_t address, unsigned int customerID, float vat, float discount, unsigned int yearlyBuy);

    [[nodiscard]] inline float getVat() const { return my_vat; }
    [[nodiscard]] inline float getDiscount() const { return my_discount; }
    [[nodiscard]] inline unsigned int getYearlyBuy() const { return my_yearlyBuy; }

    inline void setVat(float vat) { my_vat = vat; }
    inline void setDiscount(float discount) { my_discount = discount; }
    inline void setYearlyBuy(unsigned int yearlyBuy) { my_yearlyBuy = yearlyBuy; }

    static void printTopRow(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Company> Create(unsigned int customerID);

    static void selectFilter(class CustomerView& view);

private:

    static void filterVat(class CustomerView& view);
    static void filterDiscount(class CustomerView& view);

    float my_vat;
    float my_discount;
    unsigned int my_yearlyBuy;
};


#endif //PC_WINKLE_COMPANY_H
