/*********************************************************************
** Program name: Infirmary.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Infirmary Class. It
**				inherits from the "spaces" class. It lets the player
**				search the room and find a bandage.
*********************************************************************/
#include "Infirmary.hpp"
#include "Hero.hpp"
#include "UtilityFunctions.hpp"
#include <iostream>
using std::cout;
using std::endl;

//constructor, inheriting from Space
Infirmary::Infirmary() : Space("Infirmary") {
	bandageCount = 1; //1 bandage in this room
}

//interaction function. player finds and obtains a bandage
void Infirmary::interaction() {
	cout << "You cautiously enter the infirmary. Your footsteps creak." << endl;
	cout << "It looks abandoned. Everything looks old and broken." << endl;
	cout << "You rummage through the cabinets...." << endl;

	if (bandageCount == 1) {
		cout << "You find a BANDAGE in one of the cabinets." << endl; 
		bandageCount = bandageCount - 1; //subtracting 1 bandage from the room
	}
	else {
		cout << "You find nothing." << endl;
	}
}

Infirmary::~Infirmary(){}