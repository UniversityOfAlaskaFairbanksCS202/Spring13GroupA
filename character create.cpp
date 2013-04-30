//I don't think we're using this
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <time.h>

class item
{
public:
	enum type {pocket, hand};
	item()
	{
		item_type = pocket; 
		empty = 0;
		name = "initial";
	}
	item(type t, bool e, string n)
	{
		item_type = t;
		empty = e;
		name = n;
	}
	bool if_empty()
	{
		return empty;
	}
	string console_display_name()
	{
		return name;
	}
private:
	type item_type;
	bool empty;
	string name;
};
item empty_pocket(item::pocket, 1, "empty pocket");
item empty_hand(item::hand, 1, "empty");
item minora(item::hand, 0, "menorah");
item knife(item::hand, 0, "knife");

class character
{
public:
	character()
	{
		hp = 0;
		orthodoxy = 0;
		strength = 0;
		intelligence = 0;
		vertical_coordinate = 0;
		horizontal_coordinate = 0;
	}
	character(int h, int o, int s, int i)
	{
		max_hp = h;
		orthodoxy = o;
		strength = s;
		intelligence = i;
		vertical_coordinate = 0;
		horizontal_coordinate = 0;
	}
	void minus_hp(int x)
	{
		hp -= x;
	}
	void plus_hp(int x)
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
	void add_inventory_item(item x)
	{
		for (int i=0; i<4; i++)
		{
			if (pockets[i].if_empty())
			{
				pockets[i] = x;
				return;
			}
		}
		cout << "Inventory full.\n";
	}
	void drop_inventory_item()
	{
		int input;
		do
		{
			cout << "Select an item to drop:\n";
			cout << "Pockets:\n";
			for (int i=0; i<4; i++)
			{
				cout << i << ":\t" << pockets[i].console_display_name() << endl;
			}
			cout << "Hands:\n";
			for (int i=0; i<2; i++)
			{
				cout << i+4 << ":\t" << hands[i].console_display_name() << endl;
			}
			cout << "6:\tcancel\n";
			cin >> input;
		}
		while (input > 6 || input < 0);
		if (input==6)
		{
			cout << "Cancelled.\n";
			return;
		}
		else if (input < 4)
		{
			pockets[input] = empty_pocket;
			cout << pockets[input].console_display_name() << " dropped!\n";
		}
		else
		{
			hands[input-4] = empty_hand;
			cout << hands[input-4].console_display_name() << " dropped!\n";
		}
		return;
	}
	void pocket_to_hand()
	{
		int input;
		do
		{
			cout << "Select an item to hold:\n";
			cout << "Pockets:\n";
			for (int i=0; i<4; i++)
			{
				cout << i << ":\t" << pockets[i].console_display_name() << endl;
			}
			cout << "4:\tcancel\n";
			cin >> input;
		}
		while (input>4 || input<0);
		if(input==4)
		{
			cout << "Cancelled.\n";
			return;
		}
		for (int i=0; i<2; i++)
		{
			if(hands[i].if_empty())
			{
				hands[i] = pockets[input];
				return;
			}
		}
		item temp;
		temp = hands[1];
		hands[1] = pockets[input];
		pockets[input] = hands[1];
	}

private:
	int max_hp;
	int hp;
	int orthodoxy;
	int strength;
	int intelligence;
	item pockets[4];
	item hands[2];
	int vertical_coordinate;
	int horizontal_coordinate;
};

class monster
{
public:
	monster()
	{
	}
	monster(int h, int a, string n)
	{
		hp = h;
		damage = a;
		name = n;
	}
	void attack(character& PC)
	{
		int choice;
		choice = rand() % 2 + 1;
		if(choice==1)
		{
			cout << name << " attacks!\n";
			PC.minus_hp(damage);
		}
	}
	string console_display_name()
	{
		return name;
	}
protected:
	int hp;
	int damage;
	string name;
};
monster vampire_bunny(3, 1, "vampire bunny");
monster goat(5, 2, "goat");
class goat_master : public monster
{
public:
	goat_master(int h, int a, string n)
	{
		hp = h;
		damage = a;
		name = n;
	}
	void attack(character& PC)
	{
		int choice;
		choice = rand() % 2 + 1;
		if(choice==1)
		{
			cout << name << " attacks!\n";
			PC.minus_hp(damage);
		}
		if(choice==2)
		{
			cout << name << " calls a herd of goats to ram you!\n";
			PC.minus_hp(damage*3);
		}
	}
private:
};
goat_master Annie(20, 1, "Annie");

character character_create()
{
	int input;
	int hp=1, orthodoxy=1, intelligence=1, strength=1;
	for (int i=0; i<9; i++)
	{
		do
		{
			cout << "Question " << i << ":\n";
			if (i==0)
			{
				cout << "Which of the following are you best at?\n";
				cout << "1:\tBleeding for a week without dying\n";
				cout << "2:\tLifting a lot of heavy stuff\n";
				cout << "3:\tSacrificing pigeons\n";
				cout << "4:\tComing up with plans\n";
			}
			if (i==1)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==2)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==3)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==4)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==5)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==6)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==7)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==8)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			if (i==9)
			{
				cout << "<Question>\n";
				cout << "1:\t<hp>\n";
				cout << "2:\t<strength>\n";
				cout << "3:\t<orthodoxy>\n";
				cout << "4:\t<intelligence>\n";
			}
			cin >> input;
		}
		while (input<1 || input>4);
		if(input==1)
		{
			hp++;
		}
		if(input==2)
		{
			strength++;
		}
		if(input==3)
		{
			orthodoxy++;
		}
		if(input==4)
		{
			intelligence++;
		}
	}
	character PC(hp, orthodoxy, strength, intelligence);
	return PC;
}

void battle(character& PC, monster& enemy)
{
	cout << "You encounter an " << enemy.console_display_name();
}

void main()
{
	cout << "Welcome to game\n";
	character PC = character_create();
	srand(time(0));
	int enemy;
	enemy = rand() % 3 + 1;
	if (enemy==1)
	{
		battle(PC, vampire_bunny);
	}
	if (enemy==2)
	{
		battle(PC, goat);
	}
	if (enemy==3)
	{
		battle(PC, Annie);
	}
	cout << "Exiting game\n";
	system("PAUSE");
}