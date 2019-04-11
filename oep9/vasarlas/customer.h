#pragma once
#include "store.h"
#include "product.h"
#include <iostream>
#include <string>
#include <vector>
class Customer {
public:
    enum Errors { FILE_ERROR };
    Customer(const std::string& fname);
    void purchase(const Store& s);
    void putInCart(Product* p);
    friend std::ostream& operator<<(std::ostream& out, const Customer& c);
private:
    std::string _name;
    std::vector<std::string> _list;
    std::vector<Product*> _basket;
    bool linSearch(const std::string& name, Department* r, int& ind) const;
    bool minSearch(const std::string& name, Department* r, int& ind) const;
};
