#include "item.h"
#include "room.h"
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

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

	A->displayLongDescription();
	//create vector to hold inventory
	vector<Item*> inventory;
	return 0;
}
