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
#include <cmath>

#ifndef HASH_H_
#define HASH_H_

class HashNode {
private:
	long int key;
	std::string caller;

public:

	HashNode(long int u_key, std::string u_caller);

	~HashNode();

	long int getKey();

	std::string getCaller();

	void setKey(long int u_key);

	void setCaller(std::string u_caller);
};

class HashTable{
private:
	std::vector <HashNode> table;
	int size;
	int curr_size;

public:

	HashTable(int u_size);

	HashTable();

	~HashTable();

	int h1(long int key);

	int h2 (long int key);

	int hPrime(long int k, int i);

	bool isFull();

	bool isEmpty();

	void initialize(int u_size);

	void insert(long int u_key, std::string u_caller);

	void deletion(long int u_key);

	int search(long int key);

	void printCaller(long int u_key);


};


#endif /* HASH_H_ */
