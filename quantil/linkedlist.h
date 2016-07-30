///Header file to create and maintain linkedlist.

///Header file that includes the functions for creating a linkedlist which will server as value of a hash key and a datastructure to store all log informations.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

/*! Node definition of linkedlist - declares ipaddress, CPU_id, load of CPU and next pointer */
struct node{

	string key;
	int id_a, id_b, load_a, load_b;
	unsigned long log_time;
	node *next;
}; //struct node


/*! Class that implements the linkedlist using struct node*/
class linkedlist{
public:
	node *head, *tail;
	int length;
    

	linkedlist();
    
	void insert_node(node *newnode);
	void print_list();
	int get_length();
}; //class linkedlist

#endif //define linkedlist_h

