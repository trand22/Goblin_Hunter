/*********************************************************************
** Program name: BossDungeon.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Boss Dungeon class. It 
**				inherits from the Space class. It contains the 
**				goblin captain and the barricade. 
*********************************************************************/
#ifndef BOSSDUNGEON_HPP
#define BOSSDUNGEON_HPP
#include "Space.hpp"

class BossDungeon : public Space {
private:
	int goblinCaptain;

public:

	BossDungeon(); //constructor

	void interaction() override; //overridden from Space class

	int isThereAGoblinCaptain(); //checks if there's a goblin captain

	~BossDungeon(); //destructor
};




#endif
