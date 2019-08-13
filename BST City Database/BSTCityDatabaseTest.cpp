/*
 * BSTCityDatabaseTest.cpp
 *
 * Driver to test the city database implemented as a BST.
 *
 *  Created on: Aug 12, 2019
 *      Author: alex
 */

#include "CityBST.h"
#include <ctime>
#include <random>
#include <iostream>
#include <algorithm>
using std::cout; using std::to_string;

// Raise int to int power
int myPow(int x, int p)
{
	if (p == 0) return 1;
	if (p == 1) return x;

	int tmp = myPow(x, p/2);
	if (p%2 == 0) return tmp * tmp;
	else return x * tmp * tmp;
}

int main() {

	// Init variables and random distributions
	const int NUM_INSERTIONS = 10000;
	const int NUM_SEARCHES = 100;
	const int NUM_DELETIONS = NUM_SEARCHES;
	const int MAP_SIZE = 10;
	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(-MAP_SIZE,MAP_SIZE);
	std::uniform_int_distribution<> nameDistr(0,NUM_INSERTIONS-1);

	City cities[NUM_INSERTIONS];

	// Set up cities to insert
	int pos[2];
	string name;
	string baseName = "City";
	for (int i = 0; i < NUM_INSERTIONS; ++i) {
		pos[0] = posDistr(eng);
		pos[1] = posDistr(eng);
		name = baseName + std::to_string(i);
		cities[i] = City(name, pos);
	}

	std::random_shuffle(cities, cities + NUM_INSERTIONS);

	////////////
	// Insert //
	////////////

	// Init BST
	start = clock();
	CityBST BSTdatabase(cities[0]);
	for (int i = 1; i < NUM_INSERTIONS; ++i) {
		BSTdatabase.insertCity(cities[i]);
	}
	double BST_insert_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully inserted into array.\n";

	////////////
	// Search //
	////////////

	// Set up names and positions to search for
	string names[NUM_SEARCHES];
	int poses[NUM_SEARCHES][2];
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		names[i] = baseName + to_string(nameDistr(eng));
		poses[i][0] = posDistr(eng);
		poses[i][1] = posDistr(eng);
	}

	start = clock();
	// Search array by name
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		BSTdatabase.searchByName(names[i]);
	}
	double BST_name_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched array by name.\n";

	start = clock();
	// Search array by coordinate
	for (int i = 0; i < NUM_SEARCHES; ++i) {
		BSTdatabase.searchByCoordinate(poses[i]);
	}
	double BST_pos_search_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully searched array by pos.\n";

	//////////////////////////////
	// Printing within distance //
	//////////////////////////////

	// Set origin and search distance
	int origin[2];
	origin[0] = 0;
	origin[1] = 0;
	double searchDist = 2.5;

	// Print array within searchDist of origin
	start = clock();
	BSTdatabase.printWithinDistance(origin, searchDist);
	double BST_print_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Should have found at least one city in the range... \n";

	//////////////
	// Deleting //
	//////////////

	start = clock();
	// Delete from array by name
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		try {
			BSTdatabase.deleteByName(names[i]);
		} catch (const char* e) {
			cout << "Exception occurred: " << e << "\n";
		}
	}
	double BST_name_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from array by name.\n";

	start = clock();
	// Delete from array by coordinate
	for (int i = 0; i < NUM_DELETIONS; ++i) {
		try {
			BSTdatabase.deleteByCoordinate(poses[i]);
		} catch (const char* e) {
			cout << "Exception occurred: " << e << "\n";
		}
	}
	double BST_pos_delete_time = (clock() - start)/ (double) CLOCKS_PER_SEC;
	cout << "Successfully deleted from array by pos.\n";

	// Print timing results
	cout << "Time to insert into array database: " << BST_insert_time << "\n";
	cout << "Time to print within distance from array database: " << BST_print_time << "\n";
	cout << "Time to search array database by name: " << BST_name_search_time << "\n";
	cout << "Time to search array database by coordinate: " << BST_pos_search_time << "\n";
	cout << "Time to delete from array database by name: " << BST_name_delete_time << "\n";
	cout << "Time to delete from array database by coordinate: " << BST_pos_delete_time << "\n";
}

