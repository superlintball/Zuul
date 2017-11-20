#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

//general constructor, given description
Room::Room(char* newDescription)
{
	description = newDescription;
}

//define an exit
void Room::setExit(char* direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

//display the full description, with possible exits and any items
void Room::displayLongDescription()
{
	cout << "You are in room " << description << "." << endl;
	displayExitString();
}

//display all items in the room
void Room::getRoomItems()
{
	int first = 0;
	for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
	{
		if(first != 0)
		{
			cout << ", ";
		}
		first = 1;
		int position = it - items.begin();
		cout << items[position]->getDescription();
	}
	cout << endl;
}	

//display all exits and items
void Room::displayExitString()
{
	cout << "Exits: ";
	int first = 0;
	for(map<char*,Room*>::iterator it = exits.begin(); it!=exits.end(); it++)
	{
		if(first != 0)
		{
			cout << ", ";
		}
		first = 1;
		cout << it->first;
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
Room* Room::getExit(char* direction)
{
	for(map<char*,Room*>::iterator it = exits.begin(); it != exits.end(); it++)
	{
		if(strcmp(it->first,direction)==0)
		{
			return it->second;
		}
	}
	return NULL;
}

//confirm if an item is in the room
Item* Room::getItem(char* description)
{
	for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
	{
		int position = it - items.begin();
		if(strcmp(items[position]->getDescription(),description) == 0)
		{
			return items[position];
		}
	}
	return NULL;
}

//put an item in a room
void Room::setItem(Item* newItem)
{
	items.push_back(newItem);
}

//remove an item from a room
void Room::takeItem(Item* toRemove)
{
	for(vector<Item*>::iterator it = items.begin(); it != items.end(); it++)
	{
		int position = it - items.begin();
		if(items[position]==toRemove)
		{
			items.erase(items.begin()+position);
			break;
		}
	}
}
