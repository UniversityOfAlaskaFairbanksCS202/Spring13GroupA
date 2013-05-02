#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Clear.h"

character::character()
{
    hp = 0;
    y_coordinate = 0;
    x_coordinate = 0;
}
character::character(int h)
{
    max_hp = h;
    y_coordinate = 0;
    x_coordinate = 0;
}
character::character(string n, int h, int i, int s, int o, int x, int y, int z)
{
	name = n;
	max_hp = h;
	hp = max_hp;
	intelligence = i;
	strength = s;
	orthodoxy = o;
	x_coordinate = x;
	y_coordinate = y;
	z_coordinate = z;
}

void character::minus_hp(int x)
{
    hp -= x;
}
void character::plus_hp(int x)
{
    if (max_hp-hp<x)
    {
        hp = max_hp;
    }
    else
    {
        hp += x;
    }
}

int character::x()
{
  return z_coordinate;
}
int character::y()
{
  return y_coordinate;
}
int character::z()
{
  return z_coordinate;
}

bool character::add_item(item & x)
{
	for(int i=0; i<2; ++i)
	{
		if(hands[i].if_empty())
		{
			hands[i]=x;
			return 1;
		}
	}
	for(int i=0; i<4; ++i)
	{
		if(pockets[i].if_empty())
		{
			pockets[i]=x;
			return 1;
		}
	}
	cout << "Your inventory is full!\n";
	return 0;
}
void character::drop_item(coordinate & location)
{
	cout << "Which item would you like to drop?";
	for(int i=0; i<4; ++i)
	{
		cout << i << ":\t" << pockets[i].console_display_name() << endl;
	}
	for(int i=0; i<2; ++i)
	{
		cout << i+4 << ":\t" << hands[i].console_display_name() << endl;
	}
	int command;
	cin >> command;
	getline(cin, clear);

	location.item_dropped(pockets[command]);
	pockets[command]=item("empty", 0);
}
void character::pick_up_item(coordinate & location)
{
	if(location.number_items()>0)
	{
		cout << "Pick up which item?\n";
		for(int i=0; i<location.number_items(); ++i)
		{
			cout << i << ":\t" << location.items[i].console_display_name() << endl;
		}
		int command;
		cin >> command;
		getline(cin, clear);

		if(add_item(location.items[command]))
		{
			location.item_picked_up(command);
		}
	}
	else
	{
		cout << "No items to pick up.\n";
	}
}
void character::equip()
{
	cout << "Which item would you like to equip?";
	for(int i=0; i<4; ++i)
	{
		cout << i << ":\t" << pockets[i].console_display_name() << endl;
	}
	for(int i=0; i<2; ++i)
	{
		cout << i+4 << ":\t" << hands[i].console_display_name() << endl;
	}
	int command;
	cin >> command;
	getline(cin, clear);

	if(hands[0].console_display_name()=="empty")
	{
		hands[0]=pockets[command];
	}
	else if(hands[1].console_display_name()=="empty")
	{
		hands[1]=pockets[command];
	}
	else
	{
		cout << "Select an item to unequip:\n";
		for (int i=0; i<2; ++i)
		{
			cout << i << ":\t" << hands[i].console_display_name() << endl;
		}
		int command2;
		cin >> command2;
		getline(cin, clear);
		item temp=pockets[command];
		pockets[command]=hands[command2];
		hands[command2]=temp;
	}
}
void character::attack(monster & enemy)
{
	cout << "You attack!\n";
	enemy.minus_hp(1+hands[0].damage_out()+hands[1].damage_out());
}

void character::display_inventory()
{
	cout << "Pockets:\n";
	for (int i=0; i<4; ++i)
	{
		cout << pockets[i].console_display_name() << endl;
	}
	cout << "Hands:\n";
	for (int i=0; i<2; ++i)
	{
		cout << hands[i].console_display_name() << endl;
	}
}
void character::display_stats()
{
	cout << "Name:\t\t" << name  << endl << "Maximum hp:\t" << max_hp << endl << "Current hp:\t" << hp << endl << "Location:\t" << x_coordinate << "," << y_coordinate << "," << z_coordinate << endl << "Strength:\t" << strength << endl << "Intelligence:\t" << intelligence << endl << "Orthodoxy:\t" << orthodoxy << endl;
}
string character::console_display_name()
{
	return name;
}
int character::display_hp()
{
	return hp;
}

character character_create(int x, int y, int z)
{
	cout << "What's your name?\n";
	string name;
	getline(cin, name);

	int input;
    do
	{
		cout << "Which of the following are you best at?\n";
		cout << "1:\tBleeding for a week without dying\n";
		cout << "2:\tLifting a lot of heavy stuff\n";
		cout << "3:\tSacrificing pigeons\n";
		cout << "4:\tComing up with plans\n";
		cin >> input;
		getline(cin, clear);

		switch(input)
		{
		case 1:
			{
				return character(name, 100, 50, 75, 25, x, y, z);
			}
		case 2:
			{
				return character(name, 75, 25, 100, 50, x, y, z);
			}
		case 3:
			{
				return character(name, 25, 75, 50, 100, x, y, z);
			}
		case 4:
			{
				return character(name, 50, 100, 25, 75, x, y, z);
			}
		default:
			{
				cout << "Invalid input\n";
			}
		}
	}
	while(input!=1 || input!=2 || input!=3 || input!=4);
	return character();
}

int battle(character & player, monster & enemy)
{
	bool run=0;
	cout << "You encounter a " << enemy.console_display_name() << endl;
	do
	{
		cout << player.console_display_name() << endl << player.display_hp() << endl << "vs.\n" << enemy.console_display_name() << endl;
		cout << "What would you like to do?\n1:\tAttack\n2:\tRun\n";
		int command;
		cin >> command;

		switch(command)
		{
		case 1:
			{
				player.attack(enemy);
			}
		case 2:
			{
				++run;
			}
		}
		enemy.attack(player);
	}
	while(player.display_hp()>0 && enemy.display_hp()>0 && !run);
	if(player.display_hp()<=0)
	{
		cout << "You collapse from the injuries, and lose consciousness.\n";
		return 0;
	}
	else if(run)
	{
		cout << "You escape successfully.\n";
		return 1;
	}
	else if(enemy.display_hp()<=0)
	{
		cout << "You have defeated the " << enemy.console_display_name() << endl;
		return 2;
	}
	else
	{
		return 0;
	}
}

bool north(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
				return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{

			}
		}
	}
	++player.y_coordinate;
	return 1;
}
bool west(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
				return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{
				
			}
		}
	}
	--player.x_coordinate;
	return 1;
}
bool south(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
			return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{
				
			}
		}
	}
	--player.y_coordinate;
	return 1;
}
bool east(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
			return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{
				
			}
		}
	}
	++player.x_coordinate;
	return 1;
}
bool up(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
			return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{
				
			}
		}
	}
	++player.z_coordinate;
	return 1;
}
bool down(character & player)
{
	srand(0);
	if(rand() % 3 ==0)
	{
		switch(battle(player, vampire_bunny()))
		{
		case 0:
			{
			return 0;
			}
		case 1:
			{
				return 1;
			}
		default:
			{
				
			}
		}
	}
	--player.z_coordinate;
	return 1;
}