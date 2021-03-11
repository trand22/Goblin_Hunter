/*********************************************************************
** Program name: Armory.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Armory Class. It
**				inherits from the "spaces" class. It lets the player
**				search the room and find a bullet.
*********************************************************************/
#include "Armory.hpp"
#include <iostream>
using std::cout;
using std::endl;

//constructor, inheriting from Space
Armory::Armory() : Space("Armory") {
	bullet = 1; //single bullet found in the Armory
	bomb = 1; //single bomb found in armory
}

Armory::~Armory() {
	//destructor
}

//interaction function. the player finds a bullet in the armory
void Armory::interaction() {
	cout << "You are in the armory. You walk over shell casings and debris. " << endl;
	cout << "To your disappointment, all weapons have been taken." << endl;
	cout << "You look through the racks and shelves..." << endl;
	
	if (bomb != 1 && bullet != 1) {
		cout << endl;
		cout << "You have already been here. You find nothing." << endl;
	}

	if (bullet == 1) {
		cout << "You find a SINGLE .45 ACP CALIBER BULLET on the ground." << endl;
		cout << "You obtain A BULLET." << endl; 
		bullet = bullet - 1; //subtracting bullet from the room
	}

	cout << endl;

	if (bomb == 1) {
		cout << "You find a small, hardshell case on the ground. You open it up." << endl;
		cout << "Your mouth drops. You find a BOMB inside with a DETONATOR." << endl;
		cout << "This will be useful in getting rid of barricades." << endl; 
		cout << "You obtain A BOMB." << endl;
		bomb = bomb - 1; 
	}
	
}

