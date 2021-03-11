/*********************************************************************
** Program name: Main.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the main.cpp file for the Goblin Hunter game.
**				It executes the game. 
*********************************************************************/
#include "Armory.hpp"
#include "BossDungeon.hpp"
#include "Room.hpp"
#include "FirstDungeon.hpp"
#include "SecondDungeon.hpp"
#include "Goblin.hpp"
#include "GoblinCaptain.hpp"
#include "Hero.hpp"
#include "Infirmary.hpp"
#include "Lobby.hpp"
#include "Map.hpp"
#include "Space.hpp"
#include "UtilityFunctions.hpp"
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::streamsize;

int main()
{
	Map game; //creating Map object
	Hero hero; //creating hero object
	Goblin goblin1("Goblin"); //creating first goblin object
	Goblin goblin2("Goblin"); //creating second goblin object
	GoblinCaptain goblinCaptain("Goblin Captain"); //creating goblin captain object
	int firstGoblinFightCounter = 1; //goblin fight counter
	int secondGoblinFightCounter = 1; 
	int bossGoblinFightCounter = 1; //boss goblin fight counter
	int infirmaryCounter = 1; //room counter
	int armoryCounter = 1;
	int lobbyCounter = 1;
	int gameChoice = 3;

	
	//print the game intro 
	cout << "**WELCOME TO GOBLIN HUNTER**" << endl; 
	cout << "The year is 2099. The world is overrun with goblins." << endl;
	cout << "You are a GOBLIN HUNTER. " << endl;
	cout << "You take refuge in an old hotel refitted as a base for survivors. " << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "One night, you wake up and hear screams and gunshots." << endl;
	cout << "The GOBLINS have arrived to the base." << endl;
	cout << "You run outside but something HITS YOU FROM BEHIND. You are knocked out." << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "You wake up. Everything is quiet. You stand up but yell in PAIN." << endl;
	cout << "You look at your side. You are BLEEDING from a stab wound." << endl;
	cout << "You head back into your room and BANDAGE up the wound. " << endl;
	cout << "The bleeding lessens, but the wound is deep." << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "You look around the room. You find your bag." << endl;
	cout << "You open it up." << endl;
	cout << "Inside the bag is a .45 CALIBER PISTOL, 5 BULLETS, and 1 BANDAGE." << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "Now, you need INFORMATION. You close your eyes and focus." << endl;
	cout << "As a GOBLIN HUNTER, you are TRAINED to sense goblins in combat." << endl;
	cout << "You HEAR things. SMELL things. You count 3 coblins left in the building. Maybe 3 prisoners." << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "Your mission is SIMPLE: " << endl;
	cout << "1) Kill the 3 Goblins " << endl;
	cout << "2) Rescue the 3 prisoners " << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "**NOTE: If you run out of BULLETS, you will DIE in BATTLE." << endl;
	cout << "**NOTE: Your ENERGY is LIMITED. Waste too many STEPS and you will FAINT and DIE." << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "**TIP: INTERACT WITH EVERY ROOM FOR MAXIMUM PLAYABILITY.**" << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "**TIP: Use the MAP to figure out where to go!" << endl;
	cout << endl;
	cout << "Press ENTER to Continue..." << endl;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << "**BEGIN GOBLIN HUNTER**" << endl;
	cout << endl;

	//begin the game 
	hero.displayHeroStats();
	cout << endl;
	game.getCurrentPtr()->displayRoomInfo();
	cout << endl;
	game.getCurrentPtr()->displayDirectionalAwareness();

	//begin game loop
	while (hero.getSteps() > 0 && hero.getGoblinKills() < 3 && hero.getHeroHealth() > 0) {
		
		cout << endl;
		cout << "Select digits '1' --> '7' for the following options: " << endl;
		cout << "1) Move North " << endl;
		cout << "2) Move East " << endl;
		cout << "3) Move South " << endl;
		cout << "4) Move West " << endl;
		cout << "5) Interact With " << game.getCurrentPtr()->getRoom() << endl;
		cout << "6) Display Stats & Map " << endl;
		cout << "7) QUIT PROGRAM " << endl;
		int playerChoice = getInt();

		while (!(playerChoice >= 1 && playerChoice <= 7)) {
			cout << "Invalid choice. Enter digits '1' to '7'" << endl;
			playerChoice = getInt();
		}

		cout << endl;
		cout << "***************************" << endl;
		cout << endl;

		if (playerChoice == 1) { //move north
			if (game.getCurrentPtr()->getNorth() != NULL) { //if there's something in the north
				game.setCurrentPtr(game.getCurrentPtr()->getNorth()); //set currentPtr to North location
				game.getCurrentPtr()->displayRoomInfo(); //display name of new room
				game.getCurrentPtr()->displayDirectionalAwareness(); //display new compass
				hero.decrementSteps(); //hero loses a step
			}
			else { //north is null
				game.setCurrentPtr(game.getCurrentPtr()->getNorth()); //function will print error
				game.getCurrentPtr()->displayRoomInfo(); 
				game.getCurrentPtr()->displayDirectionalAwareness();
				//hero does not lose a step for this
			}
		}

		if (playerChoice == 2) { //move east
			if (game.getCurrentPtr()->getEast() != NULL) {
				game.setCurrentPtr(game.getCurrentPtr()->getEast());
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
				hero.decrementSteps();
			}
			else { //east is null
				game.setCurrentPtr(game.getCurrentPtr()->getEast()); //will print error
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
			}
		}

		if (playerChoice == 3) { //move south
			if (game.getCurrentPtr()->getSouth() != NULL) {
				game.setCurrentPtr(game.getCurrentPtr()->getSouth());
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
				hero.decrementSteps();
			}
			else { //south is null
				game.setCurrentPtr(game.getCurrentPtr()->getSouth()); //will print error
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
			}
		}

		if (playerChoice == 4) { //move west
			if (game.getCurrentPtr()->getWest() != NULL) {
				game.setCurrentPtr(game.getCurrentPtr()->getWest());
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
				hero.decrementSteps();
			}
			else {
				game.setCurrentPtr(game.getCurrentPtr()->getWest()); //will print error
				game.getCurrentPtr()->displayRoomInfo();
				game.getCurrentPtr()->displayDirectionalAwareness();
			}
		}
		
		if (playerChoice == 5) { //interact with the room
			if (game.getCurrentPtr()->getRoom() == "First Dungeon") { //if player encounters dungeon
				game.getCurrentPtr()->interaction();
				
				if (firstGoblinFightCounter == 1) {
					//combat, while both are still alive
					while (!(goblin1.getGoblinHealth() <= 0 || hero.getHeroHealth() <= 0)) {
						goblin1.goblinReceiveDamage(hero.heroAttack()); //hero attacks first
						if (goblin1.getGoblinHealth() > 0) { //if goblin still alive
							hero.heroReceivesDamage(goblin1.goblinAttack()); //goblin attacks
						}
					}
					//combat is over
					cout << endl;
					if (goblin1.getGoblinHealth() <= 0) {
						hero.incrementGoblinKills();
						hero.incrementPrisonersSaved();
						firstGoblinFightCounter = firstGoblinFightCounter + 1; //change the counter variable
					}
					
				}
			}
			
			if (game.getCurrentPtr()->getRoom() == "Second Dungeon") {
				game.getCurrentPtr()->interaction();

				if (secondGoblinFightCounter == 1) {
					//combat, while both are still alive
					while (!(goblin2.getGoblinHealth() <= 0 || hero.getHeroHealth() <= 0)) {
						goblin2.goblinReceiveDamage(hero.heroAttack()); //hero attacks first
						if (goblin2.getGoblinHealth() > 0) {
							hero.heroReceivesDamage(goblin2.goblinAttack()); //goblin attacks
						}
					}
					//combat is over
					cout << endl;
					if (goblin2.getGoblinHealth() <= 0) {
						hero.incrementGoblinKills();
						hero.incrementPrisonersSaved();
						secondGoblinFightCounter = secondGoblinFightCounter + 1; //change counter variable
					}
					
				}
			}
			
			if (game.getCurrentPtr()->getRoom() == "Boss Dungeon") {
				
				if (hero.findBombInVector() == true && hero.getGoblinKills() == 2){ //if hero has a bomb
					cout << "You set the bomb to the barricade." << endl;
					cout << "You hit the detonator. It EXPLODES with fury." << endl;
					cout << "You peek inside." << endl;
					cout << "Press ENTER to Continue..." << endl;
					cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
					game.getCurrentPtr()->interaction();

					if (bossGoblinFightCounter == 1) {
						while (!(goblinCaptain.getGoblinCaptainHealth() <= 0 || hero.getHeroHealth() <= 0)) {
							goblinCaptain.goblinCaptainReceiveDamage(hero.heroAttack()); //hero attacks
							if (goblinCaptain.getGoblinCaptainHealth() > 0) { //if captain still alive
								hero.heroReceivesDamage(goblinCaptain.goblinAttack()); //goblin captain attacks
							}
						}
						//combat is over
						cout << endl;
						if (goblinCaptain.getGoblinCaptainHealth() <= 0) {
							hero.incrementGoblinKills();
							hero.incrementPrisonersSaved();
							bossGoblinFightCounter = bossGoblinFightCounter + 1;
						}
						
					}
				}
				else {
					cout << "A barricade stands in your way. You will need something to get rid of it." << endl;
					cout << "NOTE: KILL ALL GOBLIN MINIONS before proceeding past this barricade." << endl;
				}
			}

			if (game.getCurrentPtr()->getRoom() == "Infirmary") {
				game.getCurrentPtr()->interaction(); //get the bandage
				if (infirmaryCounter == 1) {
					hero.addBandageToVector();
					infirmaryCounter = infirmaryCounter - 1;
				}
			}
			
			if (game.getCurrentPtr()->getRoom() == "Armory") {
				game.getCurrentPtr()->interaction(); //go to the armory
				if (armoryCounter == 1) {
					hero.addBombToVector(); //add a bomb
					hero.addBullet(); //add a bullet
					armoryCounter = armoryCounter - 1;
				}
			}

			if (game.getCurrentPtr()->getRoom() == "Lobby") {
				game.getCurrentPtr()->interaction();
				if (lobbyCounter == 1) {
					hero.addPhotographToVector();
					lobbyCounter = lobbyCounter - 1;
				}
			}

			if (game.getCurrentPtr()->getRoom() == "Starting Room") {
				game.getCurrentPtr()->interaction();
			}
			
		}

		if (playerChoice == 6) {
			hero.displayHeroStats();
			cout << endl;
			game.getCurrentPtr()->displayDirectionalAwareness();
		}

		if (playerChoice == 7) {
			exit(0);
		}
		
		cout << endl;
		
	}
	//outside of main game loop
	cout << "////////////////////////////////////" << endl;
	
	//victory and loss scenarios
	if (hero.getHeroHealth() <= 0 && hero.getGoblinKills() < 2) {
		cout << endl;
		cout << "You have run out of health. You look at your wounds and smirk." << endl;
		cout << "Your hands tremble and you're brought to your knees..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Your mind gets muddled and images of friends and lovers run past..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You see someone. Muddled. And a great river and big blue skies, shining fiercely." << endl;
		cout << "YOU SAY: 'Maybe I'll see you again, Jackie...'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You thankfully DIE just before the GOBLIN chops off your head." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Such is the life of a..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "**GOBLIN HUNTER** " << endl;
		cout << endl;
	}
	if (hero.getGoblinKills() >= 3) {
		cout << endl;
		cout << "You walk over the body of the GOBLIN CAPTAIN. For good measure, you kick in his skull." << endl;
		cout << "You free the last prisoner from the ceiling. She drops onto the ground." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "She looks at you in fear, and then hurriedly joins the other prisoners." << endl;
		cout << "The prisoners hug her for comfort and hand her a dirty water bottle." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "She GRATEFULLY drinks it." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "One of them SPEAKS." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'All of our friends are dead. Where do we go now? How do we LIVE?'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'HOW?' ANSWER ME!'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "The prisoner cries softly." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You look at them as you find the exit of the building." << endl;
		cout << "You pause at the door. You turn around." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "YOU SAY: How would I know? I don't know. In the end, I'm just a..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "******GOBLIN HUNTER*******" << endl;
	}
	if (hero.getSteps() <= 0) {
		cout << endl;
		cout << "You bring your foot forward and your legs collapse." << endl;
		cout << "You curse. You wasted too much energy. You didn't have a lot of time." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You look at your side. The bleeding has come back. Full force." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You don't have a lot of time left." << endl;
		cout << "Might as well make yourself comfortable." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You find a nearby wall and sit down. You lean on it." << endl;
		cout << "Memories of past friendships and lovers swim through your head..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "YOU WHISPER TO YOURSELF " << endl;
		cout << "'Maybe I'll see you again, Jackie.'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "A small smile forms on your face as everything goes to black..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Such is the life for a..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "**GOBLIN HUNTER**" << endl;
	}
	if (hero.getGoblinKills() == 2) {
		cout << endl;
		cout << "The FORCE of the Goblin Captain's attack KNOCKS you off your FEET." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You COLLIDE into a nearby wall. You hear bones break. Ribs shatter." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Your bandages come undone. The wound flows freely now." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "The GOBLIN CAPTAIN walks over to you, his steps shake the earth." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "It speaks to you, AMUSED." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "'Is that all your strength? All you have?'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "With ONE ARM it picks you up." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You look at it. Then your smile breaks into a small smirk." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You reach into your pocket and bring out a small CHUNK of the BOMB." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You DETONATE IT POINT BLANK." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "The prisoners take cover. BRIGHT LIGHTS and BOOMS cover the room." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "When the dust settles, nothing can be seen." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Such is the life of a..." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "***GOBLIN HUNTER***" << endl;
	}


}


