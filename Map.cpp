/*********************************************************************
** Program name: Map.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Map class. It contains
**				pointer-related functions that construct the overall
**				map as well as map-related functions to track the
**				player's movement.
*********************************************************************/
#include "Map.hpp"
#include "Space.hpp"
#include "Armory.hpp"
#include "FirstDungeon.hpp"
#include "SecondDungeon.hpp"
#include "Infirmary.hpp"
#include "Room.hpp"
#include "Lobby.hpp"
#include "BossDungeon.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;


/*
this is the constructor. It sets up all the initial rooms to form a map
for the player to traverse. The player will start off in the generic
"room".
*/
Map::Map() {
	//creating the new rooms
	roomPtr = new Room();
	lobbyPtr = new Lobby();
	firstDungeonPtr = new FirstDungeon();
	secondDungeonPtr = new SecondDungeon(); 
	bossDungeonPtr = new BossDungeon();
	armoryPtr = new Armory();
	infirmaryPtr = new Infirmary();

	//setting up the map by setting pointers for each room
	
	roomPtr->setNorth(NULL);
	roomPtr->setEast(lobbyPtr);
	roomPtr->setSouth(NULL);
	roomPtr->setWest(NULL);

	lobbyPtr->setNorth(NULL);
	lobbyPtr->setEast(NULL);
	lobbyPtr->setSouth(firstDungeonPtr);
	lobbyPtr->setWest(roomPtr);

	firstDungeonPtr->setNorth(lobbyPtr);
	firstDungeonPtr->setWest(NULL);
	firstDungeonPtr->setSouth(NULL);
	firstDungeonPtr->setEast(infirmaryPtr);

	infirmaryPtr->setNorth(NULL);
	infirmaryPtr->setWest(firstDungeonPtr);
	infirmaryPtr->setSouth(armoryPtr);
	infirmaryPtr->setEast(secondDungeonPtr);

	armoryPtr->setNorth(infirmaryPtr);
	armoryPtr->setWest(NULL);
	armoryPtr->setSouth(NULL);
	armoryPtr->setEast(NULL);

	secondDungeonPtr->setNorth(NULL);
	secondDungeonPtr->setWest(infirmaryPtr);
	secondDungeonPtr->setSouth(NULL);
	secondDungeonPtr->setEast(bossDungeonPtr);

	bossDungeonPtr->setNorth(NULL);
	bossDungeonPtr->setEast(NULL);
	bossDungeonPtr->setWest(secondDungeonPtr);
	bossDungeonPtr->setSouth(NULL);

	currentPtr = roomPtr; //set player starting position

}

//destructor. frees up the memory set by the pointers
Map::~Map() {
	delete roomPtr;
	delete lobbyPtr;
	delete firstDungeonPtr;
	delete infirmaryPtr;
	delete secondDungeonPtr;
	delete armoryPtr;
	delete bossDungeonPtr;
}

//this function returns the ptr where player is currently located
Space* Map::getCurrentPtr() {
	return currentPtr;
}

//check if an adjacent ptr is null and does not represent a movable space
bool Map::isSpaceNull(Space* spacePtr) {
	if (spacePtr == NULL) {
		return true;
	}
	else {
		return false;
	}
}

/*
this is the "movement" function. It sets the currentPtr to whatever location 
the user wants to go in.
*/
void Map::setCurrentPtr(Space* spacePtr) {
	if (isSpaceNull(spacePtr)) {
		cout << "ERROR: CANNOT MOVE HERE." << endl;
	}
	else {
		currentPtr = spacePtr;
	}
}





