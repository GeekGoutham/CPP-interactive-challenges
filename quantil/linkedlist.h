#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>
#include <string>
using namespace std;

struct node
{
	string key;
	unsigned long log_time;
	node *next;
};

class linkedlist
{
public:
    node *head, *tail;
    int length;
    

    linkedlist();
    
    void insert_node( node *newnode );
//    bool remove_node( string node_key );
//    node* get_node( string node_key );
    void print_list();
    int get_length();
    ~linkedlist();
};

#endif

