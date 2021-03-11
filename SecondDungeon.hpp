/*********************************************************************
** Program name: SecondDungeon.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Dungeon class. It contains
**				an interactive function for combat and a variable for
**				a prisoner.
*********************************************************************/
#ifndef SECONDDUNGEON_HPP
#define SECONDDUNGEON_HPP
#include "Space.hpp"

class SecondDungeon : public Space {
private:
	int goblin;


public:

	SecondDungeon(); //constructor

	void interaction() override; //interaction function, overridden from Space

	int isThereAGoblin(); //check if there is a goblin

	virtual ~SecondDungeon();

};



#endif
