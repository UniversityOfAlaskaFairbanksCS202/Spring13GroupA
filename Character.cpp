//I think we can get rid of the questions for character creation, as well as stats for orthodoxy, strength, & intelligence & only use the hp, also, we need a bool for the key items so that the player can get into the garage w the garagedoor opener & into the farmhouse with the house key
#include "Character.h"
#include "Item.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

character::character()
{
    hp = 0;
    orthodoxy = 0;
    strength = 0;
    intelligence = 0;
    vertical_coordinate = 0;
    horizontal_coordinate = 0;
}
character::character(int h, int o, int s, int i)
{
    max_hp = h;
    orthodoxy = o;
    strength = s;
    intelligence = i;
    vertical_coordinate = 0;
    horizontal_coordinate = 0;
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
void character::add_inventory_item(item x)
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
void character::drop_inventory_item()
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
        item empty_pocket(item::pocket, 1, "empty pocket");
        pockets[input] = empty_pocket;
        cout << pockets[input].console_display_name() << " dropped!\n";
    }
    else
    {
        item empty_hand(item::hand, 1, "empty");
        hands[input-4] = empty_hand;
        cout << hands[input-4].console_display_name() << " dropped!\n";
    }
    return;
}
void character::pocket_to_hand()
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

//player movement functions
void character::north()
{
    ++y_coordinate;
}
void character::west()
{
    --x_coordinate;
}
void character::south()
{
    --y_coordinate;
}
void character::east()
{
    ++x_coordinate;
}
void character::up()
{
    ++z_coordinate;
}
void character::down()
{
    --z_coordinate;
}