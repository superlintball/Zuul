#include <iostream>
#include "room.h"

using namespace std;

Room::Room(char* newDescription)
{
	description = newDescription;
}

void Room::setExit(char* direction, Room* neighbor)
{
	exits.insert(pair<char*,Room*>(direction, neighbor));
}

void Room::displayLongDescription()
{
	cout << "You are " << description << "." << endl;
	displayExitString();
}

void Room::displayExitString()
{
	cout << "Exits: ";

}
