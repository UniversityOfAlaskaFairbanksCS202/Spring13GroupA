#include <string>
using std::string;
#include <iostream>
using std::cout;
#include "Monster.h"
#include "Character.h"

monster::monster()
{
}
monster::monster(int h, int d, string n)
{
    hp = h;
    damage = d;
    name = n;
}

int monster::display_hp()
{
	return hp;
}
string monster::console_display_name()
{
    return name;
}

void monster::minus_hp(int x)
{
	hp-=x;
}
void monster::plus_hp(int x)
{
	hp+=x;
}

void vampire_bunny::attack(character & player)
{
	cout << "The bunny attacks!\n";
	player.minus_hp(damage);
}
void goat::attack(character & player)
{
	srand(0);
	if(rand() % 5==0)
	{
		cout << "The goat charges!\n";
		player.minus_hp(damage+rand() % 3);
	}
	else
	{
		cout << "The goat attacks!\n";
		player.minus_hp(damage);
	}
}
void annie_the_goat_master::attack(character & player)
{
	srand(0);
	if(rand() % 3==0)
	{
		cout << "Annie summons a goat!\n";
		battle(player, goat());
	}
	else
	{
		cout << "Annie attacks you!\n";
		player.minus_hp(damage);
	}
}

vampire_bunny::vampire_bunny()
{
	name="Vampire bunny";
	damage=1;
	hp=3;
}
goat::goat()
{
	name="Goat";
	damage=3;
	hp=5;
}
annie_the_goat_master::annie_the_goat_master()
{
	name="Annie the Goat Master";
	damage=2;
	hp=25;
}