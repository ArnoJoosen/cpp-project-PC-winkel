//
// Created by arno on 2/12/23.
//

#include <fstream>
#include "Invoice.h"
#include "Company.h"

Invoice::Invoice(unsigned int invoiceID, const std::weak_ptr<Customer>& customer) :
    my_invoiceID(invoiceID), my_customer(customer), my_components({}){
}

void Invoice::calculatePrice() {
    totalPrice = 0;
    for (const auto& component : my_components) {
        if (auto component_ptr = component.lock()) { // check if component still exists
            if (component_ptr->getStock() <= 0)
                throw std::runtime_error("Component no longer in stock");
            totalPrice += component_ptr->getPrice();
            component_ptr->setStock(component_ptr->getStock()-1);
        } else
            std::cout << "Component no longer exists" << std::endl;
    }
    if (auto customer_ptr = my_customer.lock()) {
        if (customer_ptr->getType() == CustomerType_t::BEDRIJF) {
            auto company_ptr = std::static_pointer_cast<Company>(customer_ptr);
            totalPrice *= (company_ptr->getDiscount()/100);
            company_ptr->setYearlyBuy(company_ptr->getYearlyBuy() + totalPrice);
        } else {
            totalPrice *= 1.21;
        }
    } else
        throw std::runtime_error("Customer no longer exists");
}

void Invoice::print() const {
    // print components
    ComponentBase::printHeader();
    for (const auto& component : my_components) {
        if (auto component_ptr = component.lock()) { // check if component still exists
            component_ptr->printBase();
            std::cout << std::endl;
        }
        else
            std::cout << "Component no longer exists" << std::endl;
    }
    std::cout << "Total price: " << totalPrice << " €" << std::endl;
}

void Invoice::save(const std::string &pwd) const {
    std::ofstream file(pwd + "/" + std::to_string(my_invoiceID) + ".txt");
    if (!file.is_open()) {
        throw std::runtime_error("Kan het bestand niet openen");
    }
    file << "Factuur: " << my_invoiceID << "\n";

    file << "Klant: " << my_customer.lock()->getCustomerID() << my_customer.lock()->getName().firstName.c_str()
         << " " << my_customer.lock()->getName().lastName.c_str() << "\n";

    file << "Adres: " << my_customer.lock()->getAddress().city.c_str() << ", " << my_customer.lock()->getAddress().street.c_str()
         << " " << my_customer.lock()->getAddress().houseNumber << " " << my_customer.lock()->getAddress().postcode << "\n";

    file << "Componenten: " << "\n";
    for (const auto& component : my_components) {
        if (auto component_ptr = component.lock()) { // check if component still exists
            file << "\t" << component_ptr->getName().c_str() << " " << component_ptr->getPrice() << " €" << "\n";
        }
        else
            std::cout << "Component no longer exists" << "\n";
    }

    file << "Totaal: " << totalPrice << " €" << std::endl;
}
