#pragma once
#include "product.h"
#include <vector>

class Department
{
    public:
        enum Errors {FileError};
        Department(const std::string &fname);
        void takeOutFromStock(int ind);
        Product* getProduct(int i) const { return _stock[i]; }
        unsigned int stockPiece() const { return _stock.size(); }
    private:
        std::vector<Product*> _stock;
};
