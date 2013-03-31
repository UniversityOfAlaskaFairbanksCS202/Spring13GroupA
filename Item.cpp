#include "Item.h"
#include <string>
using std::string;


enum type {pocket, hand};
item::item()
{
	item_type = pocket; 
	empty = 0;
	name = "initial";
}
item::item(type t, bool e, string n)
{
	item_type = t;
	empty = e;
	name = n;
}
bool item::if_empty()
{
	return empty;
}
string item::console_display_name()
{
	return name;
}