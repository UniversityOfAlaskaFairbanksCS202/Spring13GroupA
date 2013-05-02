#include <string>
using std::string;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Coordinates.h"
#include "Item.h"
#include "Clear.h"
#include "Character.h"

coordinate::coordinate()
{
	location_type="null";
	description="This is a null location, and cannot be occupied";
	number_of_items=0;
}
string coordinate::type()
{
  return location_type;
}
void coordinate::set_type(string type_)
{
	location_type=type_;
}
void coordinate::set_description(string description_)
{
	description = description_;
}
void coordinate::set(string description_, string type_)
{
	set_type(type_);
	set_description(description_);
}

string coordinate::console_display_description()
{
	return description;
}

void coordinate::item_dropped(item & x)
{
	item * temp = new item[number_of_items];
	++number_of_items;
	items = new item[number_of_items];
	for(int i=0; i<number_of_items-1; ++i)
	{
		items[i]=temp[i];
	}
	items[number_of_items]=x;
}
void coordinate::item_picked_up(int picked_item_number)
{
	item * temp_left = new item[picked_item_number-1];
	for(int i=0; i<picked_item_number-1; ++i)
	{
		temp_left[i]=items[i];
	}
	item * temp_right = new item[number_of_items-picked_item_number];
	for(int i=picked_item_number+1; i<number_of_items; ++i)
	{
		temp_right[i]=items[i];
	}
	--number_of_items;
	items = new item[number_of_items];
	for(int i=0; i<picked_item_number-1; ++i)
	{
		items[i]=temp_left[i];
	}
	for(int i=picked_item_number; i<number_of_items; ++i)
	{
		items[i]=temp_right[i];
	}
}
int coordinate::number_items()
{
	return number_of_items;
}
string coordinate::special_function_command()
{
	return special_function;
}

barn::barn()
{
	location_type="barn";
	description="Your head is pounding.  Hungover.  Again.  You don't even remember drinking last night.  It's been months since you've had anything stronger than sacrificial wine during Shabbat.  You see the setting sun through an open barn door.  Something is very, very wrong.  You are hanging upside down.  A thick rope binds your ankles and leads up to the darkness.  A knife is driven into a nearby post, almost within reach.  The rest of the barn is empty except for a rickety ladder leading up to the loft.";
	number_of_items=0;
	special_function="take knife";
}
void barn::location_special_function(character & player)
{
	player.add_item(item("knife", 3));
}

silo::silo()
{
	location_type="silo";
	description="There is a pitchfork leaning against the wall next to where the ladder is anchored.  The loft is empty except for dirt and dust, and it is very dark.  Something moves in the corner, small and brown, it hops towards you.  A bunny.  With two very sharp and pointy teeth that look surprisingly like fangs.";
	number_of_items=0;
	special_function="take pitchfork";
}
void silo::location_special_function(character & player)
{
	player.add_item(item("pitchfork", 5));
}