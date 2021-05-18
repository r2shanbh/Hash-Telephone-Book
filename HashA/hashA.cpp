/*
 * hash.cpp
 *
 *  Created on: Oct. 4, 2020
 *      Author: Raksha
 */

#include "hashA.h"

#include<iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

//////////    HashNode class definitions   ////////////////
HashNode::HashNode(long int u_key, std::string u_caller){
		key=u_key;
		caller=u_caller;
}

HashNode::~HashNode(){}

long int HashNode::getKey(){
	return key;
}

std::string HashNode::getCaller(){
	return caller;
}

void HashNode::setKey(long int u_key){
	key=u_key;
}

void HashNode::setCaller(std::string u_caller){
	caller=u_caller;
}


///////////////   HashTable class definitions   ///////////////
HashTable::HashTable(){
	size=0;
	curr_size=0;
}

HashTable::~HashTable(){
	table.clear();
}

//primary hash function
int HashTable::h1(long int key)
{
	return key % size;
}

//secondary hash function
int HashTable::h2 (long int key){
	int index=(std::floor( double(key/size) ));
	index=index % size;

	if(index%2==0){
		return index+1;
	}

	return index;
}

int HashTable::hPrime(long int k, int i){
	return ( h1(k) + i*h2(k) ) % size;
}

bool HashTable::isFull(){
	return curr_size==size;
}

bool HashTable::isEmpty(){
	return curr_size==0;
}

// to size the vector
void HashTable::initialize(int u_size){
	table.clear();

	size=u_size;
	curr_size=0;

	HashNode h(-1,"");

	for(int i=0; i<size;i++){
		table.push_back(h);
	}
	std::cout<<"success"<<std::endl;
}


// For representing the state of an empty cell -
//  0 for deleted,  -1 for empty state and any no > 0 for occupied
// inspiration for the following code from - > https://www.geeksforgeeks.org/double-hashing/
void HashTable::insert(long int u_key, std::string u_caller){
	if (isFull() || search( u_key )!=-1 ){  //if key is duplicate or table is full, -1 returned by search means the value DNE
		std::cout<<"failure"<<std::endl;
		return;
	}

	int index = h1 ( u_key );
	curr_size++;

	if(table[index].getKey()!=-1 && table[index].getKey()!=0){   //should not be empty, should not be deleted

		int iterations=1;
		while(1){
			int newIndex = hPrime(u_key,iterations);

			if (table[newIndex].getKey() == -1 || table[index].getKey()==0 ) {
				table[newIndex].setKey( u_key );
				table[newIndex].setCaller( u_caller );
				break;
			}

			iterations++;
		 }
	}

	else{  // normal insertion if key = 0 or key = -1

		table[index].setKey( u_key );
		table[index].setCaller( u_caller );
	}

	std::cout<<"success"<<std::endl;

}

void HashTable::deletion(long int u_key){
	int pos =search(u_key);
	if (isEmpty() || pos == -1){
		std::cout<<"failure"<<std::endl;
	}

	else{
		table[pos].setKey(0);  // deleted state is 0
		table[pos].setCaller("");
		curr_size--;

		std::cout<<"success"<<std::endl;
	}

}

int HashTable::search(long int key){
// -1 here indicates that key doesn't exist (DNE)
	if (isEmpty()){
		return -1;
	}

	int i = 0;

	while (table[hPrime(key,i)].getKey() != key) {
		if (table[hPrime(key,i)].getKey() == -1) {
			return -1;
		}
		i++;
	}

	return hPrime(key,i);
}

void HashTable::printCaller(long int u_key){
	int position =search(u_key);
	if (position==-1){
		std::cout<<"not found"<<std::endl;
	}
	else {
		std::cout<<"found "<<table[position].getCaller()<<" in "<<position<<std::endl;
	}
}



