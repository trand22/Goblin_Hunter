/*********************************************************************
** Program name: BossDungeon.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Boss Dungeon class. It
**				inherits from the Space class. It contains the
**				goblin captain and the barricade.
*********************************************************************/
#include "BossDungeon.hpp"
using std::cout;
using std::endl;
#include <iostream>
#include <limits>
using std::streamsize;
using std::cin;

//
BossDungeon::BossDungeon() : Space("Boss Dungeon") {
	goblinCaptain = 1; //initializing 1 goblin captain
}

//interaction function. begins combat with hero and goblin captain
void BossDungeon::interaction() {
	if (goblinCaptain == 1) {
		cout << "This dungeon is different. It's larger. Bigger. You smell dead flesh." << endl;
		cout << "A prisoner dangles from the ceiling." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "The GOBLIN CAPTAIN, as large as two men, spots you." << endl;
		cout << "IT SPEAKS, ITS VOICE GUTTURAL AND DEEP" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'So it was you who killed my minions...I will not forgive that...'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'Our kind has taken over MOTHER EARTH...she belongs to GOBLINS...'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'It has NO ROOM FOR HUMANS LIKE YOU!'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You cannot escape. You have to fight!" << endl;
		goblinCaptain = goblinCaptain - 1; //deducting goblin captain from the room
	}
	else {
		cout << "There is no goblin in this dungeon." << endl;
	}
}

int BossDungeon::isThereAGoblinCaptain() {
	if (goblinCaptain == 1) {
		return 1; //there is a goblin captain
	}
	else {
		return 0; //there is no goblin
	}
}

//destructor
BossDungeon::~BossDungeon(){}

