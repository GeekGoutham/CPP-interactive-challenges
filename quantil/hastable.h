#ifndef HashTable_h
#define HashTable_h

#include "linkedlist.h"

class HashTable
{
private:
    
    LinkedList * array;
    int length;
    int hash( string itemKey );
    
public:
    
    HashTable( int tableLength = 13 );
    void insertItem( Item * newItem );
    bool removeItem( string itemKey );
    Item * getItemByKey( string itemKey );
    void printTable();
    void printHistogram();
    int getLength();
    int getNumberOfItems();
    ~HashTable();
};

#endif
