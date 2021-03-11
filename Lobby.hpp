/*********************************************************************
** Program name: Lobby.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Lobby Class. It
**				inherits from the "spaces" class. It lets the player
**				talk to a guide that explains the backstory of the
**				goblin hunter game.
*********************************************************************/
#ifndef LOBBY_HPP
#define LOBBY_HPP
#include "Space.hpp"

class Lobby : public Space {
private:
	int photograph; //a photograph

public:
	
	Lobby(); //constructor

	void interaction() override; //interaction function, overridden from Space

	virtual ~Lobby();

};




#endif
