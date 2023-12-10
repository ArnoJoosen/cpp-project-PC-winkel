//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_COMPANY_H
#define PC_WINKLE_COMPANY_H
#include "Customer.h"
#include <memory>
#define MAX_VAT_SIZE 20
#define MAX_DISCOUNT_SIZE 8
#define MAX_YEARLY_BUY_SIZE 10

class Company : public Customer {
public:
    Company();
    Company(Name_t name, Address_t address, unsigned int customerID, const std::string& vat, float discount, float yearlyBuy);

    [[nodiscard]] inline CapString<MAX_VAT_SIZE> getVat() const { return my_vat; }
    [[nodiscard]] inline float getDiscount() const { return my_discount; }
    [[nodiscard]] inline float getYearlyBuy() const { return my_yearlyBuy; }

    inline void setVat(const std::string& vat) { my_vat = vat; }
    inline void setDiscount(float discount) { my_discount = discount; }
    inline void setYearlyBuy(float yearlyBuy) { my_yearlyBuy = yearlyBuy; }

    static void printTopRow(bool indexed = false);
    void printRow(int index) const final;
    void update() final;

    static std::shared_ptr<Company> Create(unsigned int customerID);

    static void selectFilter(class CustomerView& view);

private:

    static void filterVat(class CustomerView& view);
    static void filterDiscount(class CustomerView& view);

    CapString<MAX_VAT_SIZE> my_vat;
    float my_discount;
    float my_yearlyBuy;
};


#endif //PC_WINKLE_COMPANY_H
