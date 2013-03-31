#ifndef ITEM
#define ITEM
#include "Coordinate.h"

#include <string>
using std::string;

class item : public Coordinate
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