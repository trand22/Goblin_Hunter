/*********************************************************************
** Program name: Space.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Space class. It sets up
**				the various spaces of Goblin hunter game and will be 
**				inherited by the specialized sub-classes ("rooms")
*********************************************************************/
#include "Space.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

//constructor
Space::Space(string nameOfRoom) {
	//initializing all directional pointers to NULL
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;

	this->nameOfRoom = nameOfRoom; //setting the name of the room
}

//getters
string Space::getRoom() {
	return nameOfRoom;
}

Space* Space::getNorth() {
	return north; //return north pointer
}

Space* Space::getEast() {
	return east; //return east pointer
}

Space* Space::getSouth() {
	return south; //return south pointer
}

Space* Space::getWest() {
	return west; //return west pointer 
}

//setters
void Space::setNorth(Space* northPointer) {
	north = northPointer; //setting the north pointer
}

void Space::setEast(Space* eastPointer) {
	east = eastPointer; //setting the east pointer
}

void Space::setSouth(Space* southPointer) {
	south = southPointer; //setting the south pointer
}

void Space::setWest(Space* westPointer) {
	west = westPointer; //setting the west pointer
}

//display the name of the room the player is currently in
void Space::displayRoomInfo() {
	cout << "You are currently located in the " << getRoom() << endl;
}

//display directional awareness
void Space::displayDirectionalAwareness() {
	cout << "**DISPLAYING MAP** " << endl;
	
	if (north == NULL) { //if north has nothing
		cout << "North: Nothing" << endl;
	}
	else {
		cout << "North: " << north->getRoom() << endl;
	}

	if (east == NULL) {
		cout << "East: Nothing" << endl;
	}
	else {
		cout << "East: " << east->getRoom() << endl;
	}

	if (south == NULL) {
		cout << "South: Nothing" << endl;
	}
	else {
		cout << "South: " << south->getRoom() << endl;
	}

	if (west == NULL) {
		cout << "West: Nothing" << endl;
	}
	else {
		cout << "West: " << west->getRoom() << endl;
	}
}

Space::~Space() {}