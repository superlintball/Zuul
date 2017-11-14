#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

//general constructor, given description
Room::Room(char* newDescription)
{
	description = newDescription;
	exits = new map<char*,Room*>;
}

//define an exit
void Room::setExit(char* direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

//display the full description, with possible exits and any items
void Room::displayLongDescription()
{
	cout << "You are " << description << "." << endl;
	displayExitString();
}

//display all items in the room
void Room::getRoomItems()
{
	for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
	{
		int position = it - items.begin();
		cout << items[position]->getDescription();
		if(it != exits.end() - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}	

//display all exits and items
void Room::displayExitString()
{
	cout << "Exits: ";
	for(map<char*,Room*>::iterator it = exits.begin(); it!=exits.end(); it++)
	{
		cout << it->first;
		if(it != exits.end() - 1)
		{
			cout << ", ";
		}
	}
	if(items.empty())
	{
		cout << endl << "There are no items in the room." << endl;
	}
	else
	{
		cout << endl << "Items in the room: ";
		getRoomItems();
	}
}

//return the room that an exit points to
Room* getExit(char* direction)
{
	return exits[direction];
}

//confirm if an item is in the room
Item* getItem(char* description)
{
	for(vector<Item*>::iterator it - items.begin(); it != items.end(); it++)
	{
		int position = it - items.begin();
		if(strcmp(items[position]->getDescription(),description) == 0)
		{
			return items[position];
		}
	}
	return null;
}


