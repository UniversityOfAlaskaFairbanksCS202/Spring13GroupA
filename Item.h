//I think we can get rid of type, item needs location
#ifndef ITEM
#define ITEM
#include "Coordinate.h"

#include <string>
using std::string;

class item
{
public:
    enum type {pocket, hand};
    item();
    item(type t, bool e, string n);
    bool if_empty();
    string console_display_name();
private:
    type item_type;
    bool empty;
    string name;
};

#endif