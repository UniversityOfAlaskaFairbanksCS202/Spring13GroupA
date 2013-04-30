#include "Monster.h"
#include "Character.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;

monster::monster()
{
}
monster::monster(int h, int a, string n)
{
    hp = h;
    damage = a;
    name = n;
}
void monster::attack(character& PC)
{
    int choice;
    choice = rand() % 2 + 1;
    if(choice==1)
    {
        cout << name << " attacks!\n";
        PC.minus_hp(damage);
    }
}
string monster::console_display_name()
{
    return name;
}

goat_master::goat_master(int h, int a, string n)
{
    hp = h;
    damage = a;
    name = n;
}
void goat_master::attack(character& PC)
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