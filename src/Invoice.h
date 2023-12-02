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
    Invoice(unsigned int invoiceID, Customer* customer, const std::vector<ComponentBase*>& components);

    [[nodiscard]] inline unsigned int getInvoiceID() const { return my_invoiceID; }
    [[nodiscard]] inline const Customer* getCustomer() const { return my_customer; }
    [[nodiscard]] inline const std::vector<ComponentBase*>& getComponents() const { return my_components; }

    inline void setInvoiceID(unsigned int invoiceID) { my_invoiceID = invoiceID; }
    inline void setCustomer(Customer* customer) { my_customer = customer; }
    inline void setComponents(const std::vector<ComponentBase*>& components) { my_components = components; }

private:
    unsigned int my_invoiceID;
    Customer* my_customer;
    std::vector<ComponentBase*> my_components;
};

#endif //PC_WINKLE_INVOICE_H
