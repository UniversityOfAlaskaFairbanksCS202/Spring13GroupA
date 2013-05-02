#include <string>
using std::string;
#include "Item.h"

item::item()
{
	empty=0;
	name="empty";
	damage=0;
}
item::item(string n, int d)
{
	empty=1;
	name=n;
	damage=d;
}

bool item::if_empty()
{
	return empty;
}
string item::console_display_name()
{
    return name;
}
int item::damage_out()
{
	return damage;
}