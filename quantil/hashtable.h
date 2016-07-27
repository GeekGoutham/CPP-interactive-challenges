#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"

class hashtable{
public:
    
    linkedlist *arr_ll;
    int length;
    int hash(string node_key);
    
    
    hashtable(int tableLength = 13);
    void insert_item(node* newnode);
//    bool removeItem(string itemKey);
    linkedlist get_item_key(string node_key);
//    void printTable();
//    void printHistogram();
//    int getLength();
 //   int getNumberOfItems();
    ~hashtable();
};

#endif
