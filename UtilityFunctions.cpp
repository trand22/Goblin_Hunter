/*********************************************************************
** Program name: UtilityFunctions.cpp
** Author: 
** Date: 7/3/2019
** Description: This is the UtilityFunctions.cpp for Langton's Ant. It 
**				contains the functions that will be used to verify 
**				input from the user. 
*********************************************************************/
#include <iostream>
#include "UtilityFunctions.hpp"
#include <limits>
#include <string>
#include <ctype.h> //isdigit()
#include <sstream> //stringstream
using std::numeric_limits;
using std::streamsize;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::size_t;
using std::stoi;

/*
FROM TA TOM BEECH DURING OFFICE HOURS DEMONSTRATION

The getInt function checks whether or not the user input 
is a positive integer or not. It uses 'getline' to sort
out combinations of strings and numbers like "4dog" and
"5cat". 
*/
int getInt() {
	std::string input;
	bool invalid = true; 

	while (invalid) {

		invalid = false; 

		//Display a prompt 
		std::cout << "Enter a number: " << endl; 

		//get input from user using 'getline'
		getline(std::cin, input); 

		//iterate over every character of the input
		for (char c : input) {
			if (!isdigit(c)) {
				invalid = true;
			}
		}

		if (!invalid) {
			return stoi(input);
		}
		else {
			std::cout << "Invalid input. Please input a positive integer." << std::endl;
		}
	}
}