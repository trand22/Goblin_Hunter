/*********************************************************************
** Program name: Hero.hpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .hpp file for the Hero class. 
**				It contains functions related to the Hero of the 
**				Goblin Hunter game, such as hit points, bandage pouch, 
**				bullet pouch, and attack function.
*********************************************************************/
#ifndef HERO_HPP
#define HERO_HPP
#include <vector>
#include <string>
using std::string;
using std::vector;


class Hero {
private:
	int heroHealthPoints = 5; //health points for hero
	int bulletCount = 5; //number of bullets
	vector <string> equipmentPouch; //stores bandages and a bomb, 5 bandages MAX 
	int numberOfBandages = 0; //to keep track of bandages capacity

	int energySteps = 10; //number of steps the Hero can take before bleeding out

	int goblinKills = 0; //keeps track of goblin kills

	int prisonersSaved = 0; //keeps track of prisoners saved

public:
	Hero(); //constructor

	void displayHeroStats(); //display hero stats
	
	int heroAttack(); //hero attack function

	void heroReceivesDamage(int goblinDamage); //goblin damage 

	//add bullet function
	void addBullet(); //adds a bullet

	//vector functions
	int findBandageInVector(vector<string> Pouch); //find bandage in vector
	bool findBombInVector(); //find bomb in vector
	
	//inventory vector functions
	void addBandageToVector(); //add bandage to vector
	void addBombToVector(); //add bomb to vector
	void addPhotographToVector(); //add photograph to vector

	//goblin kill functions
	void incrementGoblinKills(); //increase Hero's kill count of goblins
	int getGoblinKills(); //getter for goblin kills

	//save prisoner functions
	void incrementPrisonersSaved();
	int returnPrisonersSaved();

	//step functions
	int getSteps(); //returns energySteps variable
	void decrementSteps(); //decrements steps

	//getter for health
	int getHeroHealth();

	

	~Hero();

};




#endif