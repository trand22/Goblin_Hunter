/*********************************************************************
** Program name: Infirmary.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Infirmary Class. It 
**				inherits from the "spaces" class. It lets the player
**				search the room and find a bandage.
*********************************************************************/
#ifndef INFIRMARY_HPP
#define INFIRMARY_HPP
#include "Space.hpp"
#include "Hero.hpp"

class Infirmary : public Space {
private:
	int bandageCount; //a bandage is in this room

public:
	Infirmary(); //constructor

	void interaction() override; //interact with room, overridden from Space class

	virtual ~Infirmary();

};




#endif




