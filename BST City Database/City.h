/*
 * City.h
 *
 * City object for database.
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef CITY_H_
#define CITY_H_

#include <string>
using std::string;

class City {
public:
	City();
	City(string name, int coord[2]); // Takes name and coordinate
	virtual ~City();
	void print(); // Prints tab-separated (City	X	Y)
	int* getPos(); // Get coordinates
	string getName(); // Get name
	int getX(); // Get X coordinate
	int getY(); // Get Y coordinate

private:
	int pos[2];
	string name;
};

#endif /* CITY_H_ */
