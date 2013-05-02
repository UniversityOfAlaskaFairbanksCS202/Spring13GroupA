#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
#include <string>
using std::string;
#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Coordinates.h"
#include "Clear.h"

void help()
{
	cout << "Commands are:\nTo move: go north, go south, go east, go west, go up, go down\nTo look around: look, observe, examine\nTo pick up an object (x): pick up x, take x, grab x\nTo talk to another character: talk to x (where x is character's name)\nTo read an item: read x (where x is item's name)\nTo use an item: use x (where x is item's name)\nFor best results, do not use capital letters or punctuation\n";
}

coordinate *** initializer(int length, int width, int height)
{
	coordinate***locations;
	locations=new coordinate**[length];
	for(int i=0; i<length; ++i)
	{
		locations[i]=new coordinate*[width];
		for (int j=0; j<height; ++j)
		{
			locations[i][j]=new coordinate[height];
		}
	}
	//Reorient the map in order to encompass our new and more efficient map composition.
	locations[1][1][0].set("Your head is pounding.  Hungover.  Again.  You don't even remember drinking last night.  It's been months since you've had anything stronger than sacrificial wine during Shabbat.  You see the setting sun through an open barn door.  Something is very, very wrong.  You are hanging upside down.  A thick rope binds your ankles and leads up to the darkness.  A knife is driven into a nearby post, almost within reach.  The rest of the barn is empty except for a rickety ladder leading up to the loft.", "barn");
	locations[1][1][1].set("There is a pitchfork leaning against the wall next to where the ladder is anchored.  The loft is empty except for dirt and dust, and it is very dark.  Something moves in the corner, small and brown, it hops towards you.  A bunny.  With two very sharp and pointy teeth that look surprisingly like fangs.", "loft");
	//locations[-1][-1][0].set("There is a silo to the southeast and a farmhouse to the west.  Cornfields surround everything.  Bright soidum lights pop on, one at a time, bathing the farm in surreal yellow light and making the shadows seem that much darker.", outside_barn);
	//locations[4][-4][0].set("The door to the silo is ajar.  The gravel at your feet is shiny with a thick, dark liquid.  Blood.  Its coppery scent is in the air.", outside_silo);
	//locations[4][-3][0].set("Hundreds, if not thousands, of black candles illuminate the inside of the silo, all ensconsed in menorahs that have been placed on shelves all around the curving walls.  A ladder leads up the wall into the darkness.  Hanging on the wall next to the ladder is a garage door opener.  A great six-pointed Star of David has been set into the floor.  A bloody goat's head floats in a pool of red, red blood at its center.", silo);
	//locations[-4][2][0].set("The garage door looms in front of you.", outside_garage);
	//locations[-4][3][0].set("In the dim light, you can see that there is no car, truck, tractor, or vehicle of any kind that you can drive away from the farm.  There is just a great empty space of gravel floor where such a vehicle should be parked.  There is a flicker and pop and suddenly your eyes are flooded with bright light.  A little girl giggles.  She sits on a stool in the corner.  There is a bunny in her lap, and she strokes it lovingly.", garage);
	//locations[-4][-2][0].set("The farmhouse creaks in the night, as though warning you away.  The windows have been boarded up, and while much of the farmhouse is in disrepair, the door is thick and strong, though deep scratch marks are gouged into its bottom, evidence of the bunnies' assault.", outside_farmhouse);
	//locations[-4][-1][0].set("The stairs leading to the upper level of the farmhouse have been cut out, and there is no way to go up.  The walls that separated the rooms on the main level have been torn down.  The kitchen has been gutted, and drippy pipes poke out into the room.  There is a door to your left.  It is open.  Bright, cheerful light emerges from it.  It leads to the basement.", farmhouse);
	//locations[-4][-1][-1].set("The basement is neat and tidy.  Another Star of David fills the center of the room.  A comfortable looking chair and a plain desk are shoved against the wall.  A notebok is open on the desk, and the shelves behind the desk are filled with similar notebooks.", basement);
	//locations[4][-3][3].set("You are at the highest goat's head.  It stinks something awful.  A swarm of flies buzzes around it.  You can see the glitter and shine of the Holy Hand Grenade clutched between the dead goat's teeth.", top_of_silo_ladder);
	return locations;
}

void main()
{
	int x=30;
	int y=30;
	int z=5;
	int start_x=0;
	int start_y=0;
	int start_z=0;
	coordinate *** locations = initializer(x, y, z);

    character player = character_create(start_x, start_y, start_z);
	cout << "Enter your command (type \"help\" for help)\n";
COMMAND:
	cout << endl;
    string command;
    getline(cin, command);

    if (command =="help")
    {
		help();
    }
	else if (command == "go north")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!north(player))
			{
				goto DEAD;
			};
		}
	}
	else if (command == "go south")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!south(player))
			{
				goto DEAD;
			};
		}
	}
	else if (command == "go east")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!east(player))
			{
				goto DEAD;
			};
		}
	}
	else if (command == "go west")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!west(player))
			{
				goto DEAD;
			};
		}
	}
	else if (command == "go up")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!up(player))
			{
				goto DEAD;
			};
		}
	}
	else if (command == "go down")
	{
		if(locations[player.x()][player.y()][player.z()-1].type()=="null")
		{
			cout << "The path is block.\n";
		}
		else
		{
			if(!down(player))
			{
				goto DEAD;
			};
		}
	}

	// commands for story to cout to screen
	else if (command=="look" || command == "observe" || command == "inspect" || command == "examine")
	{
		cout << locations[player.x()][player.y()][player.z()].type() << endl << locations[player.x()][player.y()][player.z()].console_display_description();
	}
	else if (command=="inventory" || command=="items")
	{
		player.display_inventory();
	}
	else if (command=="stats")
	{
		player.display_stats();
	}
	//commands for acquiring objects
	else if (command=="pick up")
	{
		player.pick_up_item(locations[player.x()][player.y()][player.z()]);
	}
	else if (command=="drop")
	{
		player.drop_item(locations[player.x()][player.y()][player.z()]);
	}
	else if (command==locations[player.x()][player.y()][player.z()].special_function_command())
	{
		locations[player.x()][player.y()][player.z()].location_special_function(player);
	}
	else
	{
		cout << "Command not recognized. Type \"help\" for a list of commands.\n";
	}
	goto COMMAND;
DEAD:
	return;
}