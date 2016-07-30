///Header file to include the hashtable creation and retrieval functionalities
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

/*! Implementes the hashtable functions like set and get */
class hashtable{
public:
    
	linkedlist *arr_ll;
	int length;
	int hash(string node_key);
	hashtable(int tableLength = 13);
	void insert_item(node* newnode);
	linkedlist get_item_key(string node_key);
	~hashtable();
}; // class hashtable

#endif //define HASHTABLE_H
