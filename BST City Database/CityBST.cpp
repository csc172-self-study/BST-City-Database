/*
 * CityBST.cpp
 *
 *  Created on: Jul 10, 2019
 *      Author: alex
 */

#include "CityBST.h"
#include <cmath>
#include <iostream>
#include <tuple>
using std::sqrt; using std::cout;

CityBST::CityBST() {
	tree = new BST<string,City>;
};

CityBST::CityBST(City city) {
	tree = new BST<string,City>(city.getName(), city);
}

CityBST::~CityBST() {}

void CityBST::insertCity(City inCity) {
	tree->insert(inCity.getName(), inCity);
}

BSTNode<string,City>* CityBST::searchByName(string key) {
	return tree->find(key);
}

void CityBST::deleteByName(string key) {
	tree->remove(key);
}

BSTNode<string,City>* isAtPoint(BSTNode<string, City>* node, int loc[2]) {
	City city = node->getVal();

	if (city.getX() == loc[0] && city.getY() == loc[1]) {
		return node;
	}

	return nullptr;
}

BSTNode<string,City>* CityBST::searchByCoordinate(int key[2]) {
	return tree->traverseInorder(isAtPoint, key);
}

void CityBST::deleteByCoordinate(int key[2]) {
	BSTNode<string,City>* node = searchByCoordinate(key);
	tree->remove(node->getKey());
}

bool isWithinDistance(BSTNode<string, City>* node, int orig[2], double dist) {
	City city = node->getVal();

	int xdist = city.getX()-orig[0];
	int ydist = city.getY()-orig[1];

	if (xdist*xdist + ydist*ydist <= dist*dist) {
		city.print();
		return true;
	} else {
		return false;
	}
}

void CityBST::printWithinDistance(int orig[2], double dist) {
	cout << "Name \t x \t y \n";
	tree->traversePreorder(isWithinDistance, orig, dist);
}
