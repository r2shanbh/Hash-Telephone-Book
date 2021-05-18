/*
 * hash.cpp
 *
 *  Created on: Oct. 4, 2020
 *      Author: Raksha
 */
#include<iostream>
#include <string>
#include <vector>
#include <memory>
#include <math.h>

#include "hashB.h"

//////////////////Hash List Definitions////////////////
HashList::HashList(){
	p_head=nullptr;
}

HashList::~HashList(){
	HashNode *p_walk=getHead();

	while (p_walk != nullptr){
		p_head=p_head->p_nxt;
		delete p_walk;
		p_walk=p_head;
		}

		delete p_walk;
		p_walk=nullptr;

}

HashNode* HashList::getHead(){
	return p_head;
}

bool HashList::isEmpty(){
	return p_head==nullptr;
}

// returns position in the liked list starting from 1
int HashList::search(long int u_key){
	//return -1 if list is empty
	if(isEmpty()){
		return -1;
	}

	int  position=1;  // position in the linked list (starting from 1)
	int check = 0; // flag variable whose value is set to 1 if found

	HashNode* p_walk; // pointer to travel through the list

	p_walk = p_head;

	while (p_walk->p_nxt!= nullptr && p_walk->key<=u_key){
		if(p_walk->key==u_key){//if the last key visited in the sorted array is equal to user key
			check=1;
			break;
		}

		p_walk=p_walk->p_nxt;
		position++;
	}

	if(p_walk->key==u_key){
			check =1;
	}

	if (check == 0){ // if key not found then return 0
		return -1;
	}

	return position;

}

void HashList::insertElement(long int u_key, std::string u_caller){  ///alternatively, create the memory block here?
	// cannot duplicate entries so search key
	if (search( u_key ) > 0 ){
		std::cout<<"failure"<<std::endl;
		return;
	}

	HashNode* entry = new HashNode;
	entry->key=u_key;
	entry->caller=u_caller;
	entry->p_nxt=nullptr;

	/// if it's the very first entry
	if(isEmpty()){
		p_head = entry;
		std::cout<<"success"<<std::endl;
		return;
	}

	HashNode* prev, *current;
	prev=nullptr;
	current=p_head;

	// if entry is smaller the first node
	if(entry->key < p_head->key){
		entry->p_nxt=p_head;
		p_head=entry;
		std::cout<<"success"<<std::endl;
		return;
	}


	while (current->key<entry->key && current->p_nxt!=nullptr){
		prev=current;
		current=current->p_nxt;
	}

	// if entry is greter than all nodes
	if (current->key > entry->key){
    	prev->p_nxt=entry;
    	entry->p_nxt=current;
	}
	else{
		current->p_nxt=entry;
	}
	std::cout<<"success"<<std::endl;

}

void HashList::deleteElement(long int u_key){
	int iterations = search(u_key);
	int i=1;

	if (isEmpty()||iterations==-1){
		std::cout<<"failure"<<std::endl;
		return;
	}

	HashNode *current,*after;
	current=p_head;
	after=p_head->p_nxt;

	if (current->key==u_key)
	{   p_head=after;

	    std::cout<<"success"<<std::endl;

	    delete current;
	    current=nullptr;
	}
	else {
	   while(i<iterations-1){
		   after=after->p_nxt;
		   current=current->p_nxt;
		   i++;
	   }

	   if(after->p_nxt==nullptr){
		   current->p_nxt=nullptr;

		   delete after;
		   after=nullptr;
	   }

	   else{
		   current->p_nxt=after->p_nxt;

		   delete after;
		   after=nullptr;
	   }
	   std::cout<<"success"<<std::endl;
	}
}

void HashList::printCaller (long int u_key){
	int pos=search(u_key);

	if (pos<0){
		return ;
	}
	else{
		int i=1;
		HashNode *p_walk=p_head;

		while (i!=pos){
			p_walk=p_walk->p_nxt;
			i++;
		}

		std::cout<< p_walk->caller;
	}

}

void HashList::printList(){
	if( isEmpty() ) {
		return;
	}

	HashNode* p_walk;

	p_walk=p_head;

	while (p_walk!=nullptr){
		std::cout<<p_walk->key<<" ";
		p_walk=p_walk->p_nxt;
	}
	std::cout<<std::endl;

}

//////////////////Hash Table Definitions
HashTable::HashTable(){
	size=0;
}

HashTable::~HashTable(){
	table.clear();
}

void HashTable::initialize(int u_size){
	table.clear();
	size=u_size;

	table.resize(u_size);
	std::cout<<"success"<<std::endl;
}

int HashTable::h1(long int key){
	return key % size;
}

void HashTable::insert(long int u_key, std::string u_caller){
	int index = h1 ( u_key );

	table[index].insertElement(u_key, u_caller);
}

void HashTable::deletion(long int u_key){
	int index = h1 (u_key );

	table[index].deleteElement(u_key);
}

int HashTable::getSize(){
	return size;
}

void HashTable::searchElement(long int u_key){
	int index = h1 (u_key );

	if (table[index].search(u_key)>=0){
		std::cout<<"found ";
		table[index].printCaller(u_key);
		std::cout<<" in "<<index<<std::endl;
	}
	else
	{
		std::cout<<"not found"<<std::endl;
	}
}

void HashTable::printIndexList(int index){
	table[index].printList();
}


