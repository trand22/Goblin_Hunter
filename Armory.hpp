/*********************************************************************
** Program name: Armory.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Armory Class. It
**				inherits from the "spaces" class. It lets the player
**				search the room and find a bullet.
*********************************************************************/
#ifndef ARMORY_HPP
#define ARMORY_HPP
#include "Space.hpp"
#include "Hero.hpp"

class Armory : public Space {
private:
	int bullet; //bullet in the armory
	int bomb; //bomb in the armory

public:
	Armory(); //constructor

	virtual ~Armory(); //destructor

	void interaction() override; //interact with room, overridden from Space class
};



#endif
