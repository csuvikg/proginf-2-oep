#include "Store.h"

Store::Store(const std::string &fname, const std::string &tname)
{
    _food = new Department(fname);
    _technical = new Department(tname);
}
