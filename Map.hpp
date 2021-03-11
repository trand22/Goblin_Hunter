/*********************************************************************
** Program name: Map.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Map class. It contains
**				pointer-related functions that construct the overall
**				map as well as map-related functions to track the
**				player's movement.
*********************************************************************/
#ifndef MAP_HPP
#define MAP_HPP
#include "Space.hpp"
#include "Armory.hpp"
#include "FirstDungeon.hpp"
#include "SecondDungeon.hpp"
#include "Infirmary.hpp"
#include "Room.hpp"
#include "Lobby.hpp"
#include "BossDungeon.hpp"
#include <string>

class Map {
private:
	Space* currentPtr; //current location 
	Space* roomPtr;
	Space* lobbyPtr;
	Space* firstDungeonPtr;
	Space* infirmaryPtr;
	Space* secondDungeonPtr;
	Space* armoryPtr;
	Space* bossDungeonPtr;

public:
	Map(); //default constructor

	~Map(); //destructor
	Space* getCurrentPtr(); //getter for the player's current location ptr

	bool isSpaceNull(Space* spacePtr); //check if adjacent ptr spaces are null

	void setCurrentPtr(Space* spacePtr); //set currentPtr to another ptr space


};
#endif