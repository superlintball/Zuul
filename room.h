#ifndef ROOMH
#define ROOMH

#include <iostream>
#include <map>
#include "item.h"
#include <vector>

using namespace std;

class Room
{
	public:
		Room(char* newDescription);
		void setExit(char* direction, Room* neighbor);
		void displayLongDescription();
		void displayExitString();
		Room* getExit(char* direction);
		Item* getItem(int index);
		Item* getItem(char* itemName);
		void setItem(Item* newItem);
		void getRoomItems();
		void takeItem(Item* toRemove);
	protected:
		char* description;
		map<char*,Room*> exits;
		vector<Item*> items;
};

#endif
