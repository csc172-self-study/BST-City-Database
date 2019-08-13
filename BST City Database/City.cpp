/*
 * City.cpp
 *
 * City object for database.
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#include "City.h"
#include <iostream>
using std::cout;

// Default constructor
City::City() {
	name = "";
	pos[0] = 0;
	pos[1] = 1;
}

// Takes name and coordinate array
City::City(string cityName, int coord[2]) {
	name = cityName;
	pos[0] = coord[0];
	pos[1] = coord[1];
}

// Destructor
City::~City() {

}

// Return position
int* City::getPos() {
	return pos;
}

// Return name
string City::getName() {
	return name;
}

// Return x coord
int City::getX() {
	return pos[0];
}

// Return y coord
int City::getY() {
	return pos[1];
}

// Print tab-separated
void City::print() {
	cout << name << "\t" << pos[0] << "\t" << pos[1] << "\n";
}
