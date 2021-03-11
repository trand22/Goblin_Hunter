/*********************************************************************
** Program name: Space.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Space class. It sets up 
**				the various spaces of the Goblin Hunter game and will be
**				inherited by the specialized sub-classes ("rooms").
*********************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <iostream>
using std::string;

class Space {
private:
	string nameOfRoom;
	Space* north; //setting up pointers for Space class
	Space* east; //emulating Linked List structure
	Space* south;
	Space* west;
	
public:
	Space(string nameOfRoom); //constructor for Space
	string getRoom(); //get name of the room 
	
	//getters for the pointers
	Space* getNorth();
	Space* getEast();
	Space* getSouth();
	Space* getWest();

	//setters for the pointers
	void setNorth(Space* northPointer);
	void setEast(Space* eastPointer);
	void setSouth(Space* southPointer);
	void setWest(Space* westPointer);

	//display the name of the room
	void displayRoomInfo();

	//display directional awareness
	void displayDirectionalAwareness();

	//virtual functions that will be inherited and modified
	virtual void interaction() = 0; 

	virtual ~Space();



};






#endif
