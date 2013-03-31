#include "Item.h"
#include "Character.h"
#include "Monster.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <ctime>


monster vampire_bunny(3, 1, "vampire bunny");
monster goat(5, 2, "goat");

goat_master Annie(20, 1, "Annie");

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