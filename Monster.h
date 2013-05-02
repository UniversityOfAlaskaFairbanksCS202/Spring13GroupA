#ifndef MONSTER
#define MONSTER

#include <string>
using std::string;
#include <iostream>
using std::cout;

class character;

class monster
{
public:
    monster();
    monster(int h, int d, string n);

    virtual void attack(character & player)=0;

	int display_hp();
    string console_display_name();

	void minus_hp(int x);
	void plus_hp(int x);
protected:
    int hp;
    int damage;
    string name;
};
class vampire_bunny:public monster
{
public:
	vampire_bunny();
	void attack(character & player);
private:
};
class goat:public monster
{
public:
	goat();
	void attack(character & player);
private:
};
class annie_the_goat_master:public monster
{
public:
	annie_the_goat_master();
	void attack(character & player);
private:
};

#endif