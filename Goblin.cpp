/*********************************************************************
** Program name: Goblin.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Goblin Class. It contains
**				the goblin attack function and health variable.
*********************************************************************/
#include "Goblin.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

//default constructor
Goblin::Goblin(){ }

//constructor with string parameter for name
Goblin::Goblin(string goblinName) {
	this->goblinName = goblinName;
	goblinHealth = 5; //goblin only needs to be shot once to die
}

//goblin attack function. It just returns a value of 1 damage per turn
int Goblin::goblinAttack() {
	cout << "The GOBLIN attacks you! -1 Health." << endl;
	return 1; 
}

//goblin receiving damage function. It reduces the goblin's health to 0. 
void Goblin::goblinReceiveDamage(int heroAttackDamage) {
	
	//subtract hero's attack from goblin health
	goblinHealth = goblinHealth - heroAttackDamage; 

	if (goblinHealth <= 0) {
		cout << "Goblin has no more health." << endl;
	}
}

int Goblin::getGoblinHealth() {
	return goblinHealth;
}

Goblin::~Goblin(){}