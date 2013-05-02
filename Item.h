#ifndef ITEM
#define ITEM

#include <string>
using std::string;

class item
{
public:
	item();
	item(string n, int d);

	bool if_empty();
	string console_display_name();
	int damage_out();
private:
	bool empty;
	string name;
	int damage;
};

#endif
