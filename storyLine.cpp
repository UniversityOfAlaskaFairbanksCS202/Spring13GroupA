//  main.cpp
//  groupProject
//
//  Copyright (c) 2013 annietupek. All rights reserved.
//
// need to fix the coordinate system either here to be y,x,z, or in coordinate class to be x,y,z. need to define field & gravel as coordinates, need to add in keys for entering buildings, locations for entering building, add in bounds for go up & go down commands  
#include "character.h"
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    character player;
    player = character_create();
X:
    string command;
    getline(cin, command);
    
    // command for help
    if (command =="help")
    {
        cout << "Commands are:" << endl;
        cout << "To move: go north, go south, go east, go west, go up, go down\nTo look around: look, observe, examine\nTo pick up an object: pick up x, take x, grab x (where x is the object's name)\nTo talk to another character: talk to x (where x is character's name)\nTo read an item: read x (where x is item's name)\nTo use an item: use x (where x is item's name)\n\nFor best results, do not use capital letters or punctuation
    }
    // commands for setting player's location
    else if (command == "go north")
    {
        player.north();
    }
    else if (command == "go south")
    {
        player.south();
    }
    else if (command == "go east")
    {
        player.east();
    }
    else if (command == "go west")
    {
        player.west();
    }
    else if (command == "go up")
    {
        player.up();
    }
    else if (command == "go down")
    {
        player.down();
    }
    
    // commands for story to cout to screen
    else if (command=="look" || command == "observe" || command == "inspect" || command == "examine")
    {
        if (location == field)
        {
            cout << "You are surrounded by stalks of corn, and you can hear tiny creatures scritching & scratching all around you." << endl;
        }
        if (location == gravel)
        {
            cout << "You are on a gravel path.  You should keep moving." << endl;
        }
        else if (location == 1,1,0)//in the barn
        {
            cout << "Your head is pounding.  Hungover.  Again.  You don't even remember drinking last night.  It's been months since you've had anything stronger than sacrificial wine during Shabbat.  You see the setting sun through an open barn door.  Something is very, very wrong.  You are hanging upside down.  A thick rope binds your ankles and leads up to the darkness.  A knife is driven into a nearby post, almost within reach.  The rest of the barn is empty except for a rickety ladder leading up to the loft." << endl;
        }
        else if (location == 1,1,1)//in the loft
        {
            cout << "There is a pitchfork leaning against the wall next to where the ladder is anchored.  The loft is empty except for dirt and dust, and it is very dark.  Something moves in the corner, small and brown, it hops towards you.  A bunny.  With two very sharp and pointy teeth that look surprisingly like fangs." << endl;
        }
        else if (location == -1,-1, 0)//outside the barn
        {
            cout << "There is a silo to the southeast and a farmhouse to the west.  Cornfields surround everything.  Bright soidum lights pop on, one at a time, bathing the farm in surreal yellow light and making the shadows seem that much darker." <<endl;
        }
        else if (location == 4,-4,0)//outside the silo
        {
            cout << "The door to the silo is ajar.  The gravel at your feet is shiny with a thick, dark liquid.  Blood.  Its coppery scent is in the air." << endl;
        }
        else if (location == 4,-3,0)//inside the silo, ground level
        {
            cout << "Hundreds, if not thousands, of black candles illuminate the inside of the silo, all ensconsed in menorahs that have been placed on shelves all around the curving walls.  A ladder leads up the wall into the darkness.  Hanging on the wall next to the ladder is a garage door opener.  A great six-pointed Star of David has been set into the floor.  A bloody goat's head floats in a pool of red, red blood at its center." << endl;
        }
        else if (location == -4,2,0)//outside the garage
        {
            cout << "The garage door looms in front of you." << endl;
        }
        else if (location == -4,3,0)//inside the garage
        {
            cout << "In the dim light, you can see that there is no car, truck, tractor, or vehicle of any kind that you can drive away from the farm.  There is just a great empty space of gravel floor where such a vehicle should be parked.  There is a flicker and pop and suddenly your eyes are flooded with bright light.  A little girl giggles.  She sits on a stool in the corner.  There is a bunny in her lap, and she strokes it lovingly." << endl;
        }
        else if (location == -4,-2,0)//outside farmhouse
        {
            cout << "The farmhouse creaks in the night, as though warning you away.  The windows have been boarded up, and while much of the farmhouse is in disrepair, the door is thick and strong, though deep scratch marks are gouged into its bottom, evidence of the bunnies' assault." << endl;
        }
        else if (location == -4, -1, 0)//inside the farmhouse
        {
            cout << "The stairs leading to the upper level of the farmhouse have been cut out, and there is no way to go up.  The walls that separated the rooms on the main level have been torn down.  The kitchen has been gutted, and drippy pipes poke out into the room.  There is a door to your left.  It is open.  Bright, cheerful light emerges from it.  It leads to the basement." << endl;
        }
        else if (location == -4,-1,-1)//in the basement
        {
            cout << "The basement is neat and tidy.  Another Star of David fills the center of the room.  A comfortable looking chair and a plain desk are shoved against the wall.  A notebok is open on the desk, and the shelves behind the desk are filled with similar notebooks." << endl;
        }
        else if (location ==4,-3,3)//in the silo, at top of ladder
        {
            cout << "You are at the highest goat's head.  It stinks something awful.  A swarm of flies buzzes around it.  You can see the glitter and shine of the Holy Hand Grenade clutched between the dead goat's teeth." << endl;
        }
            
    }
    
    //commands for acquiring objects
    //knife
    else if (command =="take knife" || command == "grab knife" || command == "pick up knife" && location == 1,1,0)
    {
        //acquire object-set object's bool to true
        cout << "You swing over to the knife, grab it, and manage to cut yourself free.  You fall onto the ground with a thud." << endl;
    }
    //pitchfork
    else if (command =="take pitchfork" || command == "grab pitchfork" || command == "pick up pitchfork" && location == 1,1,1)
    {
        //acquire object-set object's bool to true
        cout << "You hold the pitchfork in both hands, ready to defend yourself." << endl;
    }
    //garage door opener
    else if (command == "take garage door opener" || command == "grab garage door opener" || command == "pick up garage door opener" && location == 4,-3,0)
    {
        //acquire object-set object's bool to true
        cout << "You slip the garage door opener into your pocket." << endl;
    }
    //farm house key
    else if (command == "take key" || command == "grab key" || command == "pick up key" && location == -4,3,0)
    {
        //acquire object-set object's bool to true
        cout << "You wipe the blood and bits of fur off the key and place the key in your pocket." << endl;
    }
    //Holy Hand Grenade
    else if (command == "take holy hand grenade" || command == "grab holy hand grenade" || command == "pick up holy hand grenade" && location == 4,-3,3)
    {
        //acquire object-set object's bool to true
        cout << "You stretch out and take the Holy Hand Grenade from the goat's mouth.  It is slick with blood, and about the size and shape of a softball, except for the pin sticking out of a small cylinder on the top."<< endl;
    }
    
    //other commands for interacting w environment
    else if (command == "talk to girl" && location == -4,3,0)
    {
        cout << "\"The sacrfices didn't help, did they?\" she says, speaking to the bunny.  More bunnies hop into the garage.  They eye you with their beady eyes, but do nothing but twitch their noses at you.\n\"The goats,\" the girl says, \"He sacrificed my goats to make his Holy Hand Grenade, but my bunnies killed him before he could use it.\"\nShe looks up and meets your eyes. \"My bunnies are hungry again, and you'll feed more of them than any old billy goat ever did.\"\nThe little girl rushes at you, her army of vampire bunnies close behind." << endl;
    }
    else if (command == "read notebook" && location == -4,-1,-1)
    {
        cout << "The farmer's blocky handwriting is easy to read, espcially in the bright light of the basement.  The latest entry reads:\n\"They're coming for me.  They'll come at night.  They always come at night.  I have hidden the Holy Hand Grenade in the silo, inside the highest goat's head.  It needs one more sacrifice for full potency.  I don't know if my old limbs will be able to make that climb again.  But, I must do it.  Tonight.\nI will pull the Holy Hand Grenade's pin and count to three.  Three shall be the count and the number of the count shall be three.  Then, the grenade will do its duty and take me along to the grave with the vampire bunnies and the girl.  It is what I deserve.\""<< endl;
    }
    else if (command == "use holy hand grenade")
    {
        cout << "You pull the pin.  One.  Two.  Three.  BOOM!" << endl;
    }
    else // to catch all other commands
    {
        cout << "I did not understand your command.  Please see the help information for the commands I do understand." << endl;
    }
    goto X;

    return 0;
}

