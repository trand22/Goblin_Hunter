/*********************************************************************
** Program name: Hero.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Hero class.
**				It contains functions related to the Hero of the
**				Goblin Hunter game, such as hit points, bandage pouch,
**				bullet pouch, and attack function.
*********************************************************************/
#include "Hero.hpp"
#include "UtilityFunctions.hpp"
#include <iostream>
#include <string>
#include <limits>
using std::endl;
using std::cout;
using std::cin;
using std::streamsize;



//constructor
Hero::Hero() {
	heroHealthPoints = 5; //starting health
	bulletCount = 5; //starting bullet count
	equipmentPouch.push_back(".45 Colt Pistol"); //put a gun in equipment pouch
	equipmentPouch.push_back("Bandage"); //one bandage in equipment pouch
	energySteps = 10; //energy of 10 steps 
	goblinKills = 0; 
	prisonersSaved = 0;

}

//this function finds a bandage in the pouch
int Hero::findBandageInVector(vector<string> pouch) {
	if (pouch.size() > 0) { //if it has stuff in it
		for (unsigned int i = 0; i < pouch.size(); i++) { //go through the pouch
			if (pouch[i] == "Bandage") {
				return i; //return the location
			}
		}
	}
	else {
		cout <<"Pouch is empty." << endl;
		return -1; //return -1 if pouch is empty
	}

	return -1;
}

/*
this function finds a bomb in the pouch. Because there is only one bomb
in the whole game, we can just use a bool function.
*/
bool Hero::findBombInVector() {
	if (equipmentPouch.size() > 0) { //if stuff is inside the pouch
		for (unsigned int i = 0; i < equipmentPouch.size(); i++) { //go through pouch
			if (equipmentPouch[i] == "Bomb") { //find bomb 
				return true;
			}
		}
	}
	else { //if pouch is empty
		return false;
	}

	return false;
}

/*
The hero attack function has three options: two shots, one shot, and heal. The shots
have different percentage chances as well as bullet costs. Heal will first search
in the equipmentPouch vector for a "Bandage" value, remove it from the vector,
and then heal the player's health by 1 point. 
*/

int Hero::heroAttack() {
	cout << endl;
	cout << "HERO HEALTH POINTS: " << heroHealthPoints << endl;
	cout << "BULLET COUNT: " << bulletCount << endl;
	cout << endl;
	cout << "You have three options: " << endl;
	cout << endl;
	cout << "1) Two shots to the chest: 75% hit chance.(-2 Bullet)" << endl;
	cout << "2) 1 shot to the head: 50% hit chance. (-1 Bullet)" << endl; 
	cout << "3) Heal (-1 Bandage, +1 Health)" << endl;
	cout << "Enter '1' or '2' or '3' " << endl; 
	int combatChoice = getInt(); 

	while (!(combatChoice == 1 || combatChoice == 2 || combatChoice == 3)) {
		cout << "Invalid input. Enter '1', '2', or '3'." << endl; 
	}
	
	cout << endl;

	if (combatChoice == 1) {
		if (bulletCount >= 2) { //if there are enough bullets
			if (rand() % 100 < 75) { //75 percent chance of hit
				cout << "Your two shots slam into the goblin's chest." << endl;
				cout << "2 bullet deduction." << endl;
				bulletCount = bulletCount - 2;
				return 10; //Goblin health will be 5. This is automatic kill.
			}
			else {
				cout << endl;
				cout << "No luck. You missed both shots." << endl;
				cout << "2 bullet deduction." << endl;
				bulletCount = bulletCount - 2;
				return 0;
			}
		}
		else {
			cout << "You do not have enough bullets." << endl;
			cout << "You are ATTACKED as your finger hesitates on the trigger!" << endl;
			return 0;
		}
		
	}

	if (combatChoice == 2) {
		if (bulletCount >= 1) { //if there are enough bullets
			if (rand() % 100 < 50) { //50 percent chance of hit
				cout << "Your single bullet shoots through the goblin's head. Nice shot." << endl;
				cout << "1 bullet deduction." << endl;
				bulletCount = bulletCount - 1;
				return 5; //Goblin health will be 5. This is automatic kill.
			}
			else {
				cout << endl;
				cout << "No luck. You missed your headshot." << endl;
				//cout << "The GOBLIN attacks you! -1 Health." << endl;
				cout << "1 bullet deduction." << endl;
				bulletCount = bulletCount - 1;
				return 0;
			}
		}
		else {
			cout << "You do not have enough bullets." << endl;
			cout << "The GOBLIN attacks as you hesitate with your trigger!" << endl;
			return 0;
		}
		
	}

	if (combatChoice == 3) {
		//locate bandage in pouch and delete it
		if (findBandageInVector(equipmentPouch) != -1) { //if there's a bandage
			//erase it from the vector
			equipmentPouch.erase(equipmentPouch.begin() + findBandageInVector(equipmentPouch)); 
			cout << endl;
			cout << "You use a bandage to heal yourself. Increasing health by 2." << endl;
			cout << "You are ATTACKED as you heal yourself!" << endl;
			cout << "Deduct 1 bandage." << endl;
			heroHealthPoints = heroHealthPoints + 2; //heal up 2 points
			return 0;
		}
		else { //there are no bandages
			cout << "Healing unsuccessful." << endl;
			return 0;
		}
	}

	return 0;

}

//this function displays the stats and condition of the hero
void Hero::displayHeroStats() {
	cout << "**STATS** " << endl;
	cout << "Bullet Count: " << bulletCount << endl;
	cout << "Health Points: " << heroHealthPoints << endl;
	cout << "Steps left: " << energySteps << endl;
	cout << "Goblin Kills: " << goblinKills << endl;
	cout << "Prisoners saved: " << prisonersSaved << endl;
	
	//printing inventory
	if (equipmentPouch.size() > 0) { //if it has stuff inside
		cout << "Pouch: ";
		for (unsigned int i = 0; i < equipmentPouch.size(); i++) {
			cout << equipmentPouch[i] << " || ";
		}
		cout << endl;
	}
	else {
		cout << "Pouch: EMPTY" << endl;
	}
}
  
//this function decrements Hero's health if attacked by a goblin
void Hero::heroReceivesDamage(int goblinDamage) {
	heroHealthPoints = heroHealthPoints - goblinDamage;
}

//this function adds a bandage to the equipment pouch vector. It has a capacity of 5.
void Hero::addBandageToVector() {

	for (unsigned int i = 0; i < equipmentPouch.size(); i++) { //go through pouch
		if (equipmentPouch[i] == "Bandage") { //find bandage
			numberOfBandages++; //count number of bandages
		}		
	}

	if (numberOfBandages < 5) { //if its less than 5
		equipmentPouch.push_back("Bandage"); //one bandage in equipment pouch
		cout << "Adding 1 bandage to inventory!" << endl;
	}
	else {
		cout << "Can't add bandage! Inventory full. Discarding bandage." << endl;
	}
}



//this function adds a bomb to the equipment pouch vector. No capacity limit. It is a special item.
void Hero::addBombToVector() {
	equipmentPouch.push_back("Bomb"); //adding bomb to vector
}

//this function adds a photograph to the equipment pouch vector. No capacity limit. It is a special item.
void Hero::addPhotographToVector() {
	equipmentPouch.push_back("Photograph"); //adding photograph to vector
}

//this function increments goblin kills if Hero is able to kill a goblin
void Hero::incrementGoblinKills() {
	goblinKills = goblinKills + 1; //incrementing goblin kills
	cout << "Number of Goblin Kills increased by 1. " << endl;
}

//this getter function returns the number of goblin kills
int Hero::getGoblinKills() {
	return goblinKills; //return the goblin kills variable
}

//this function increments the number of prisoners saved
void Hero::incrementPrisonersSaved() {
	prisonersSaved = prisonersSaved + 1; //incrementing by 1
	cout << "You saved a prisoner!" << endl;
}

//this getter function returns the number of prisoners saved
int Hero::returnPrisonersSaved() {
	return prisonersSaved; //returning prisoners saved variable
}

//this function returns the energySteps variable
int Hero::getSteps() {
	return energySteps;
}

//this function decrements the energySteps variable by 1
void Hero::decrementSteps() {
	cout << endl;
	energySteps = energySteps - 1;
	cout << "Deduct 1 Steps Energy." << endl;
	cout << "Steps Energy Left: " << energySteps << endl;
	cout << endl;
}

//this getter retrieves the hero's health
int Hero::getHeroHealth() {
	return heroHealthPoints;
}

//this function adds a bullet to the gun
void Hero::addBullet() {
	bulletCount = bulletCount + 1;
}

Hero::~Hero(){}
