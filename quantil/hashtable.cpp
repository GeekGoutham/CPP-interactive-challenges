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
    return (value * node_key.length() ) % length;
}

void hashtable::insert_item(node *newnode){
    int index = hash(newnode->key);
    arr_ll[index].insert_node(newnode);
}
/*
bool hashtable::remove_item(string node_key){
    int index = hash(node_key);
    return arr_ll[index].removeItem(itemKey);
}
*/
linkedlist hashtable::get_item_key(string node_key){
    int index = hash(node_key);
    return arr_ll[index];
}
/*
void HashTable::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

void HashTable::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

int HashTable::getLength()
{
    return length;
}

int HashTable::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}
*/
hashtable::~hashtable()
{
    delete []arr_ll;
}
