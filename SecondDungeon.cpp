/*********************************************************************
** Program name: SecondDungeon.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Dungeon class. It contains
**				an interactive function for combat and a variable for
**				a prisoner.
*********************************************************************/
#include "SecondDungeon.hpp"
#include <iostream>
using std::cout;
using std::endl;

//constructor
SecondDungeon::SecondDungeon() : Space("Second Dungeon") {
	goblin = 1;
}

//interaction function. this begins COMBAT between Hero and Goblin
void SecondDungeon::interaction() {
	if (goblin == 1) {
		cout << "You are in a dungeon. A prisoner is shackled to the wall." << endl;
		cout << "A GOBLIN, guarding the prisoner, spots you." << endl;
		cout << "You cannot escape. You have to fight!" << endl;
		goblin = goblin - 1; //deduct goblin from the dungeon
	}
	else {
		cout << "There is no goblin in this dungeon." << endl;
	}
}

//function checks to see if dungeon has a goblin or not 
int SecondDungeon::isThereAGoblin() {
	if (goblin == 1) {
		cout << "There is a goblin in this dungeon." << endl;
		return 1; //return 1 if there is a goblin
	}
	else {
		return 0; //no goblin in this dungeon
	}
}

SecondDungeon::~SecondDungeon() {}