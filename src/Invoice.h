//
// Created by arno on 10/25/23.
//

#ifndef PC_WINKLE_INVOICE_H
#define PC_WINKLE_INVOICE_H
#include <vector>
#include <memory>
#include "Customer.h"
#include "Component.h"

class Invoice {
public:
    using ComponentList = std::vector<std::shared_ptr<Component>>;

    Invoice();

    [[nodiscard]] inline int getInvoiceID() const {return my_invoiceID;}
    inline void setInvoiceID(int invoiceID) {my_invoiceID = invoiceID;}

    [[nodiscard]] inline Customer& getCustomerD() const {return my_customer;}
    inline void setCustomer(Customer& customer) {my_customer = customer;}

    [[nodiscard]] inline Customer& getComponents() const {return my_customer;}
    void addComponent(Component component);

    [[nodiscard]] inline float getTotalPrice() const {return totalPrice;}

private:
    void calculateTotalPrice();

    int my_invoiceID;
    Customer& my_customer;
    ComponentList components;
    float totalPrice;
};


#endif //PC_WINKLE_INVOICE_H
