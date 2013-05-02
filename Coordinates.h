#ifndef COORDINATE
#define COORDINATE

#include <string>
using std::string;
#include "Item.h"

class character;

class coordinate
{
public:
	coordinate();

	void set_type(string type_);
	void set_description(string description_);
	void set(string description_, string type_);

	string console_display_description();
	string type();

	void item_dropped(item & x);
	void item_picked_up(int picked_item_number);
	int number_items();
	item * items;

	virtual void location_special_function(character & player);
	string special_function_command();
protected:
	string location_type;
	string special_function;
	string description;
	int number_of_items;
};
class barn:public coordinate
{
public:
	barn();
	void location_special_function(character & player);
private:
};
class silo:public coordinate
{
public:
	silo();
	void location_special_function(character & player);
private:
};
class garage:public coordinate
{
public:
	garage();
	void location_special_function(character & player);
private:
};
class loft:public coordinate
{
public:
	loft();
	void location_special_function(character & player);
private:
};

#endif