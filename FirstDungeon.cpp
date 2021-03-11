/*********************************************************************
** Program name: FirstDungeon.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Dungeon class. It contains
**				an interactive function for combat and a variable for
**				a prisoner.
*********************************************************************/
#include "FirstDungeon.hpp"
#include <iostream>
using std::cout;
using std::endl;

//constructor
FirstDungeon::FirstDungeon() : Space("First Dungeon") {
	goblin = 1;
}

//interaction function. this begins COMBAT between Hero and Goblin
void FirstDungeon::interaction() {
	if (goblin == 1) {
		cout << endl;
		cout << "You are in a dungeon. A prisoner is shackled to the wall." << endl;
		cout << "A GOBLIN, guarding the prisoner, spots you." << endl;
		cout << "You cannot escape. You have to fight!" << endl;
		goblin = goblin - 1; //deduct goblin from the dungeon
		cout << endl;
	}
	else {
		cout << "There is no goblin in this dungeon." << endl;
	}
}

//function checks to see if dungeon has a goblin or not 
int FirstDungeon::isThereAGoblin() {
	if (goblin == 1) {
		cout << "There is a goblin in this dungeon." << endl;
		return 1; //return 1 if there is a goblin
	}
	else {
		return 0; //no goblin in this dungeon
	}
}

FirstDungeon::~FirstDungeon(){}