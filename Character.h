#ifndef CHARACTER
#define CHARACTER

#include <iostream>
using std::cin;
using std::cout;
#include "Coordinates.h"
#include "Item.h"
#include "Monster.h"

class character
{
public:
	character();
	character(int h);
	character(string n, int h, int i, int s, int o, int x, int y, int z);

	void minus_hp(int x);
	void plus_hp(int x);

	int x();
	int y();
	int z();

	bool add_item(item & x);
	void drop_item(coordinate & location);
	void pick_up_item(coordinate & location);
	void equip();
	void attack(monster & enemy);

	void display_inventory();
	void display_stats();
	string console_display_name();
	int display_hp();

	friend int battle(character & player, monster & enemy);
	friend bool north(character & player);
	friend bool south(character & player);
	friend bool east(character & player);
	friend bool west(character & player);
	friend bool up(character & player);
	friend bool down(character & player);
private:
    int max_hp;
    int hp;
    item pockets[4];
	item hands[2];
    int x_coordinate;
    int y_coordinate;
    int z_coordinate;
    int intelligence;
    int strength;
    int orthodoxy;
	string name;
};

character character_create(int x, int y, int z);

#endif