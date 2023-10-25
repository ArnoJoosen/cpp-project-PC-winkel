//
// Created by arno on 10/25/23.
//

#ifndef PC_WINKLE_CUSTOMER_H
#define PC_WINKLE_CUSTOMER_H
#include <string>

class Customer {
public:
    Customer(std::string name, std::string address);

    [[nodiscard]] inline std::string getName() const {return my_name;}
    inline void setName(std::string name) {my_name = name;}

    [[nodiscard]] inline std::string getAddress() const {return  my_address;}
    inline void setAddress(std::string address) {my_address = address;}
private:
    std::string my_name;
    std::string my_address;
    bool company = false;
};


#endif //PC_WINKLE_CUSTOMER_H
