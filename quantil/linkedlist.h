#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string>
using namespace std;

struct node{

	string key;
	int id_a, id_b, load_a, load_b;
	unsigned long log_time;
	node *next;
};

class linkedlist{
public:
	node *head, *tail;
	int length;
    

	linkedlist();
    
	void insert_node(node *newnode);
	void print_list();
	int get_length();
};

#endif

