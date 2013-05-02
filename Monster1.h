#ifndef MONSTER
#define MONSTER

#include "Coordinate.h"
#include "Character.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;

class monster : public Coordinate
{
public:
    monster();
    monster(int h, int a, string n);
    void attack(character& PC);
    string console_display_name();
protected:
    int hp;
    int damage;
    string name;
};

#endif

#ifndef GOAT_MASTER
#define GOAT_MASTER

class goat_master : public monster
{
public:
    goat_master(int h, int a, string n);
    void attack(character& PC);
private:
};

#endif
