/*
 * hash.h
 *
 *  Created on: Oct. 4, 2020
 *      Author: Raksha
 */
#include<iostream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>

#ifndef HASH_H_
#define HASH_H_

/// All class declarations for chaining

struct HashNode{
	long int key;
	std::string caller;
	HashNode* p_nxt;
};


class HashList{
private:
	HashNode* p_head;

public:
	HashList();

	~HashList();

	HashNode* getHead();

	bool isEmpty();

	int search(long int u_key);

	void insertElement(long int u_key, std::string u_caller);

	void deleteElement(long int u_key);

	void printList();

	void printCaller (long int u_key);


};


class HashTable{
private:
	int size;
	std::vector <HashList> table;

public:

	HashTable();

	~HashTable();

	void initialize(int size);

	int h1(long int key);

	int getSize();

	void insert(long int u_key, std::string u_caller);

	void deletion(long int u_key);

	void searchElement(long int u_key);

	void printIndexList(int index);

};


#endif /* HASH_H_ */
