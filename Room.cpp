/*********************************************************************
** Program name: Room.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Room class. It inherits
**				from the space class. This is the starting point for
**				the player.
*********************************************************************/
#include "Room.hpp"
#include <iostream>
using std::cout;
using std::endl;

Room::Room() : Space("Starting Room") {
	//nothing
}

void Room::interaction() {
	cout << "You look around you in the room. There is nothing here." << endl;
	cout << "You should leave the room." << endl;
}

Room::~Room(){}