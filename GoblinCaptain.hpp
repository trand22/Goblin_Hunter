/*********************************************************************
** Program name: GoblinCaptain.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Goblin Captain Class. 
**				It inherits from the original Goblin class and modifies
**				attack and health values.
*********************************************************************/
#ifndef GOBLINCAPTAIN_HPP
#define GOBLINCAPTAIN_HPP
#include "Goblin.hpp"

class GoblinCaptain : public Goblin {
public:

	GoblinCaptain(string goblinName); //constructor for Goblin Captain

	int goblinAttack() override; //attack function for goblin captain, overridden

	void goblinCaptainReceiveDamage(int heroAttackDamage); //receive damage

	int getGoblinCaptainHealth(); //get health for captain

	~GoblinCaptain();

};



#endif