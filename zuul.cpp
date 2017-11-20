/* Author: Raveen Karnik
 * Date: 11-20-17
 * This program is a text-based adventure game. */

#include "item.h"
#include "room.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void printHelp();

int main()
{
	//create the rooms
	Room* A = new Room((char *)"A");
	Room* B = new Room((char *)"B");
	Room* C = new Room((char *)"C");
	Room* D = new Room((char *)"D");
	Room* E = new Room((char *)"E");
	Room* F = new Room((char *)"F");
	Room* G = new Room((char *)"G");
	Room* H = new Room((char *)"H");
	Room* I = new Room((char *)"I");
	Room* J = new Room((char *)"J");
	Room* K = new Room((char *)"K");
	Room* L = new Room((char *)"L");
	Room* M = new Room((char *)"M");
	Room* N = new Room((char *)"N");
	Room* O = new Room((char *)"O");
	Room* P = new Room((char *)"P");

	//initialize room exits
	O->setExit((char *)"Door1", F);
        F->setExit((char *)"Door1", O);
        
        A->setExit((char *)"Door2", F);
        F->setExit((char *)"Door2", A);

        A->setExit((char *)"Door3", E);
        E->setExit((char *)"Door3", A);

        A->setExit((char *)"Door4", G);
        G->setExit((char *)"Door4", A);

        F->setExit((char *)"Door5", G);
        G->setExit((char *)"Door5", F);

        F->setExit((char *)"Door6", I);
        I->setExit((char *)"Door6", F);

        B->setExit((char *)"Door7", B);

        E->setExit((char *)"Door8", G);
        G->setExit((char *)"Door8", E);

        G->setExit((char *)"Door9", I);
        I->setExit((char *)"Door9", G);

        G->setExit((char *)"Door10", H);
        H->setExit((char *)"Door10", G);

        H->setExit((char *)"Door11", I);
        I->setExit((char *)"Door11", H);

        B->setExit((char *)"Door12", I);
        I->setExit((char *)"Door12", B);

        I->setExit((char *)"Door13", P);
        P->setExit((char *)"Door13", I);

        E->setExit((char *)"Door14", H);
        H->setExit((char *)"Door14", E);

        B->setExit((char *)"Door15", H);
        H->setExit((char *)"Door15", B);

        B->setExit((char *)"Door16", P);
        P->setExit((char *)"Door16", B);

        C->setExit((char *)"Door17", P);
        P->setExit((char *)"Door17", C);
	
	C->setExit((char *)"Door18", P);
        P->setExit((char *)"Door18", C);

        C->setExit((char *)"Door19", P);
        P->setExit((char *)"Door19", C);

        C->setExit((char *)"Door20", P);
        P->setExit((char *)"Door20", C);

        B->setExit((char *)"Door21", H);
        H->setExit((char *)"Door21", B);

        J->setExit((char *)"Door22", P);
        P->setExit((char *)"Door22", J);

        B->setExit((char *)"Door23", E);
        E->setExit((char *)"Door23", B);

        B->setExit((char *)"Door24", J);
        J->setExit((char *)"Door24", B);

        D->setExit((char *)"Door25", J);
        J->setExit((char *)"Door25", D);

        B->setExit((char *)"Door26", D);
        D->setExit((char *)"Door26", B);

        B->setExit((char *)"Door27", K);
        K->setExit((char *)"Door27", B);

        E->setExit((char *)"Door28", K);
        K->setExit((char *)"Door28", E);

        D->setExit((char *)"Door29", M);
        M->setExit((char *)"Door29", D);

        K->setExit((char *)"Door30", M);
        M->setExit((char *)"Door30", K);

        E->setExit((char *)"Door31", N);
        N->setExit((char *)"Door31", E);

        K->setExit((char *)"Door32", L);
        L->setExit((char *)"Door32", K);

        L->setExit((char *)"Door33", M);
        M->setExit((char *)"Door33", L);

        D->setExit((char *)"Door34", K);
        K->setExit((char *)"Door34", D);

	//create vector to hold inventory
	vector<Item*> inventory;
	//create pointer to hold what room the player is in, and start them in B
	Room* currentRoom = B;
	
	//there are four keys throughout the map
	E->setItem(new Item("GoldKey"));
	C->setItem(new Item("BronzeKey"));
	D->setItem(new Item("IronKey"));
	L->setItem(new Item("SilverKey"));
	
	//Once the player has Cheese Pizza the game will end
	O->setItem(new Item("CheesePizza"));

	printHelp();

	//game plays until the user quits or wins
	bool playing = true;
	while(playing)
	{
		//always display the information of the room the player is in
		cout << endl;
		currentRoom->displayLongDescription();

		//ask for the command the user wants to do
		cout << endl << "Enter a command word." << endl;
		char input[100];
		cin.get(input, 100);
		cin.get();
		cout << endl;
		
		//if they want to go somewhere, ask where and go there if possible
		if(strcmp(input,"go") == 0)
		{
			cout << "go where?" << endl;
			char direction[30];
			cin.get(direction,29);
			cin.get();

			//if the location they want to go is valid
			if(currentRoom->getExit(direction)!=NULL)
			{
				//if the door they want to go through is the final door
				if(strcmp(direction,"Door1")==0)
				{
					//make sure they have all the items
					if(inventory.size() == 4 && currentRoom==F)
					{
						cout << "This door has four locks: one iron, one bronze, one silver, and one gold." << endl;
						cout << "You have all 4 keys. The door unlocks." << endl;
						currentRoom = O;
					}
					//don't let them leave if they're in the final room
					else if(currentRoom==O)
					{
						cout << "There is no handle on this side of the door. You can't go back." << endl;
					}
					//if they are neither in the final room nor have all items, don't let them through
					else
					{
						cout << "This door has four locks: one iron, one bronze, one silver, and one gold." << endl;
						cout << "You can't unlock the doors." << endl;
					}

				}
				//if they want to go through any other door, let them
				else
				{
					currentRoom = currentRoom->getExit(direction);
				}
			}
			else
			{
				cout << "That door doesn't exist." << endl;
			}
		}
		//if the user wants to quit, quit
		else if(strcmp(input,"quit") == 0)
		{
			playing = false;
		}
		//display the beginning message again
		else if(strcmp(input,"help") == 0)
		{
			printHelp();
		}
		//take an item from the room
		else if(strcmp(input, "get") == 0)
		{
			cout << "get what?" << endl;
			char item[30];
			cin.get(item,30);
			cin.get();
			//make sure the item they want is there, then add it
			if(currentRoom->getItem(item)!=NULL)
			{
				inventory.push_back(currentRoom->getItem(item));
				currentRoom->takeItem(currentRoom->getItem(item));
				cout << "You have taken the " << item << "." << endl;
				//WIN CONDITION: IF THEY HAVE THE CHEESE PIZZA, THEY WIN
				if(strcmp(item,"CheesePizza")==0)
				{
					cout << "You eat the Cheese Pizza. It's delicious." << endl;
					playing = false;
				}
			}
			else
			{
				cout << "That item doesn't exist here." << endl;
			}
		}
		//display all items in the inventory
		else if(strcmp(input, "inventory")==0)
		{
			if(inventory.empty())
			{
				cout << "You have no items" << endl;
			}
			else
			{
				cout << "Your inventory contains: " << endl;
				int first = 0;
				for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++)
				{
					if(first != 0)
					{
						cout << ", ";
					}
					first = 1;
					int position = it - inventory.begin();
					cout << inventory[position]->getDescription();
				}
				cout << endl;
			}
		}
		//remove an item from the inventory
		else if(strcmp(input, "drop") == 0)
		{
			cout << "drop what?" << endl;
			char item[30];
			cin.get(item,30);
			cin.get();

			//make sure the item they want to drop is in their inventory before dropping it
			bool found = false;
			for(vector<Item*>::iterator it = inventory.begin(); it != inventory.end(); it++)
			{
				int position = it - inventory.begin();
				if(strcmp(inventory[position]->getDescription(),item)==0)
				{
					currentRoom->setItem(inventory[position]);
					inventory.erase(inventory.begin()+position);
					cout << item << " dropped." << endl;
					found = true;
					break;
				}
			}
			if(!found) cout << "You don't have that item." << endl;
		}
		else
		{
			cout << "I'm sorry I couldn't understand that." << endl;
		}
	}

	return 0;
}

//prints opening message
void printHelp()
{
	cout << "You wake up in a room with no discernible features." << endl;
	cout << "You don't remember who you are, where you've woken up, or how you got here." << endl;
	cout << "Your stomach is growling. You want food." << endl;
	cout << endl << "Your command words are:" << endl;
	cout << "'go', 'quit', 'help', 'inventory', 'get', and 'drop'" << endl;
}
