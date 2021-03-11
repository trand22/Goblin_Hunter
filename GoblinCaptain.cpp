/*********************************************************************
** Program name: GoblinCaptain.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Goblin Captain Class.
**				It inherits from the original Goblin class and modifies
**				attack and health values.
*********************************************************************/
#include "GoblinCaptain.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

//constructor with string parameter for name
GoblinCaptain::GoblinCaptain(string goblinName) {
	this->goblinName = goblinName;
	this->goblinHealth = 15; //increased health
}

//goblin captain attack, overridden from goblin class
int GoblinCaptain::goblinAttack() {
	cout << "The goblin CAPTAIN attacks. It knocks the WIND out of you." << endl;
	cout << "deduct 2 points of damage!" << endl;
	return 2; //twice as powerful as a normal goblin, returns 2 damage
}

//goblin captain receive damage function
void GoblinCaptain::goblinCaptainReceiveDamage(int heroAttackDamage) {
	
	//subtract hero's attack from goblin health
	goblinHealth = goblinHealth - heroAttackDamage;

	if (goblinHealth <= 0) {
		cout << "Goblin Captain has no more health." << endl;
	}
}

int GoblinCaptain::getGoblinCaptainHealth() {
	return goblinHealth;
}

GoblinCaptain::~GoblinCaptain(){}

