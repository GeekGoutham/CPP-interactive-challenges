#include "hashtable.h"

hashtable::hashtable(int table_length){

	if (table_length <= 0) table_length = 13;
	arr_ll = new linkedlist[table_length];
	length = table_length;
}

int hashtable::hash( string node_key ){

	int value = 0;
	for (int i = 0; i < node_key.length(); i++)
		value += node_key[i];
	return ((value * node_key.length() ) % length);
}

void hashtable::insert_item(node *newnode){

	int index = hash(newnode->key);
	arr_ll[index].insert_node(newnode);
}

linkedlist hashtable::get_item_key(string node_key){

	int index = hash(node_key);
	return arr_ll[index];
}

hashtable::~hashtable(){

    delete []arr_ll;
}
