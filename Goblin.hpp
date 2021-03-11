/*********************************************************************
** Program name: Goblin.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Goblin Class. It contains
**				the goblin attack function and health variable.
*********************************************************************/
#ifndef GOBLIN_HPP
#define GOBLIN_HPP
#include <string>
using std::string;

class Goblin {
protected:
	int goblinHealth;
	string goblinName;

public:

	Goblin(); //default constructor
	
	Goblin(string goblinName); //constructor with string parameter for name

	virtual int goblinAttack(); //attack function for Goblin
	
	void goblinReceiveDamage(int heroAttackDamage); //goblin receives damage

	int getGoblinHealth(); //returns goblin health

	virtual ~Goblin();

};




#endif
