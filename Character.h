#ifndef CHARACTER
#define CHARACTER

#include "Coordinate.h"
#include "Item.h"

class character
{
public:
    character();
    character(int h, int o, int s, int i);
    void minus_hp(int x);
    void plus_hp(int x);
    void add_inventory_item(item x);
    void drop_inventory_item();
    void pocket_to_hand();
    void north();
    void west();
    void south();
    void east();
    void up();
    void down();
private:
    int max_hp;
    int hp;
    int orthodoxy;
    int strength;
    int intelligence;
    item pockets[4];
    item hands[2];
    int x_coordinate;
    int y_coordinate;
    int z_coordinate;
};

#endif

#ifndef CHARACTER_CREATE
#define CHARACTER_CREATE

character character_create();

#endif
