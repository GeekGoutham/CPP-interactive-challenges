///Program that implements hashtable and its functions - insert, get hash, retrieve and the destructor
#include "hashtable.h"

/*! Hashtable constructor builds base table */
hashtable::hashtable(int table_length){

	if (table_length <= 0) table_length = 13;
	arr_ll = new linkedlist[table_length];
	length = table_length;
}

/*! Creates the hash of the input key which is the location where the value would be stored */
int hashtable::hash( string node_key ){

	int value = 0;
	for (int i = 0; i < node_key.length(); i++)
		value += node_key[i];
	return ((value * node_key.length() ) % length);
}

/*! Inserts a node into the hashtable */
void hashtable::insert_item(node *newnode){

	int index = hash(newnode->key);
	arr_ll[index].insert_node(newnode);
}

/*! Gets am item from the hashtable using key*/
linkedlist hashtable::get_item_key(string node_key){

	int index = hash(node_key);
	return arr_ll[index];
}

/*! Destructs tha hastable upon loosing reference in program*/
hashtable::~hashtable(){

    delete []arr_ll;
}
