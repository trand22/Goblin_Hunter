/*********************************************************************
** Program name: Lobby.cpp
** Author: Dan Tran
** Date: 8/10/2019
** Description: This is the .cpp file for the Lobby Class. It
**				inherits from the "spaces" class. It lets the player
**				talk to a guide that explains the backstory of the
**				goblin hunter game.
*********************************************************************/
#include "Lobby.hpp"
#include "UtilityFunctions.hpp"
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;

Lobby::Lobby() : Space("Lobby") {
	photograph = 1; // a photograph in the lobby
}

void Lobby::interaction() {
	if (photograph >= 1) {
		cout << "You step into the lobby." << endl;
		cout << "A man is on the ground, clutching a wound on his chest. It seems fatal." << endl;
		cout << "You approach him." << endl;
		cout << "The man sees you." << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "He says: 'Jesus, I can't believe they left someone alive. What a miracle.'" << endl;
		cout << "He says: 'They killed everyone. Mostly. Took some prisoners. Some goblin stabbed me. Got me good.'" << endl;
		cout << "He coughs blood." << endl;
		cout << "He says: 'Help me onto that couch and I'll tell you what's up ahead.'" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "You spot a couch near the wall. Do you help him up and put him onto the couch?" << endl;
		cout << "Press ENTER to Continue..." << endl;
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		cout << "Press '1' to help him onto the couch" << endl;
		cout << "Press '2' to leave him to die. No time to waste." << endl;
		int playerChoice = getInt();

		while (!(playerChoice == 1 || playerChoice == 2)) {
			cout << "Invalid choice. Please enter '1' or '2'." << endl;
			playerChoice = getInt();
		}

		if (playerChoice == 1) {
			cout << endl;
			cout << "You help him up and put him on the couch. He thanks you." << endl;
			cout << "He says: 'They're mostly all gone. There's only a few of them left.'" << endl;
			cout << "He says: 'They're guarding 3 prisoners. One of the guards is the GOBLIN CAPTAIN.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "He says: 'He's strong. Twice as strong. He inflicts 2x damage.'" << endl;
			cout << "He says: 'He's behind a barricade. You'll need something to blow it up.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "He says: 'There's an armory and an infirmary up ahead. Maybe you'll find something there.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "The man reaches into his pocket." << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "He says: 'Take this PHOTOGRAPH. Do me a favor. Put it somewhere outside where there's sunlight.'" << endl;
			cout << "The man chokes up blood. He whispers the name of a woman, and then dies on the couch." << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "You have obtained a PHOTOGRAPH." << endl;
			photograph = photograph - 1; //photograph is gone from lobby
		}
		if (playerChoice == 2) {
			cout << endl;
			cout << "You choose to do nothing." << endl;
			cout << "The man looks at you, then smirks." << endl;
			cout << "He says: 'No compassion, huh? That's good. You'll need it to get out of here.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "He says: 'As long as you kill those goblin bastards, I'll tell you this one thing: " << endl;
			cout << "He says: 'The wound in your side doesn't look too good. You'll faint soon.'" << endl;
			cout << "He says: 'Better rescue some prisoners so they help you out.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "He says: '...and hope they are kinder to you than you were to me.'" << endl;
			cout << "Press ENTER to Continue..." << endl;
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "The man chokes up blood. He curses at you quietly, then dies." << endl;
			photograph = photograph - 1; //negating this conversation from happening again
		}
	}
	else {
		cout << "You have already been here. The man lies dead." << endl;
	}
}

Lobby::~Lobby() {}


