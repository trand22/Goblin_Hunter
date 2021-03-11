/*********************************************************************
** Program name: Room.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Room class. It inherits
**				from the space class. This is the starting point for
**				the player. 
*********************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include "Space.hpp"

class Room : public Space {
public:
	Room(); //constructor

	void interaction() override; //interaction function, overridden from Space

	virtual ~Room(); //destructor

};



#endif
