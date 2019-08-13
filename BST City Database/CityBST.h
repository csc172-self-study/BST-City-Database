/*
 * CityArrayList.h
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#ifndef CITYBST_H_
#define CITYBST_H_

#include "BST.h"
#include "City.h"
#include <string>
using std::string; using std::pair;

class CityBST {
private:
	BST<string, City>* tree;

public:
	CityBST();
	CityBST(City city);
	virtual ~CityBST();

	void insertCity(City city);
	BSTNode<string,City>* searchByName(string key);
	void deleteByName(string key);
	BSTNode<string,City>* searchByCoordinate(int key[2]);
	void deleteByCoordinate(int key[2]);
	void printWithinDistance(int orig[2], double dist);
};

#endif /* CITYBST_H_ */
