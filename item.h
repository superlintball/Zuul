#ifndef ITEMH
#define ITEMH

#include <iostream>

using namespace std;
class Item
{
	public:
		Item(char* newDescription) {description = newDescription;};
		char* getDescription() {return description;};
	protected:
		char* description;		
};

#endif
