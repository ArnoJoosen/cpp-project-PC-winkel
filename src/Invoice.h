//
// Created by arno on 2/12/23.
//

#ifndef PC_WINKLE_INVOICE_H
#define PC_WINKLE_INVOICE_H
#include <vector>
#include "Components/ComponentBase.h"
#include "Customer.h"

class Invoice {
public:
    Invoice(unsigned int invoiceID, const std::weak_ptr<Customer>& customer);

    [[nodiscard]] inline unsigned int getInvoiceID() const { return my_invoiceID; }
    [[nodiscard]] inline std::weak_ptr<Customer> getCustomer() const { return my_customer; }
    [[nodiscard]] inline const std::vector<std::weak_ptr<ComponentBase>>& getComponents() const { return my_components; }

    inline void setInvoiceID(unsigned int invoiceID) { my_invoiceID = invoiceID; }
    inline void setCustomer(const std::weak_ptr<Customer>& customer) { my_customer = customer; }
    inline void addComponents(const std::weak_ptr<ComponentBase>& component) { my_components.push_back(component); }

    void print() const;

private:
    unsigned int my_invoiceID;
    std::weak_ptr<Customer> my_customer;
    std::vector<std::weak_ptr<ComponentBase>> my_components;
};

#endif //PC_WINKLE_INVOICE_H
