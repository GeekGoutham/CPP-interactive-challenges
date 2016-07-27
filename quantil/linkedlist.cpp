#include "linkedlist.h"

linkedlist::linkedlist()
{
    head = new node;
    head -> next = NULL;
    length = 0;
}

void linkedlist::insert_node( node *newnode )
{
    if (!head -> next)
    {
        head -> next = newnode;
        length++;
        return;
    }
    node *p = head;
    node *q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newnode;
    newnode -> next = NULL;
    length++;
}

bool linkedlist::remove_node( string node_key ) //qwliurhfgoiqwurhgfoiuqwhrg
{
    if (!head -> next) return false;
    node *p = head;
    node *q = head;
    while (q)
    {
        if (q -> key == node_key)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

node* linkedlist::get_node( string node_key )
{
    node *p = head;
    node *q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == node_key))
            return p;
        q = p -> next;
    }
    return NULL;
}

void linkedlist::print_list()
{
    if (length == 0)
    {
        cout << "List : Empty";
        return;
    }
    node *p = head;
    while (p -> next != NULL)
    {
       cout << "Key - IP : " << p->key << "    "  << "Time : " << p->log_time << endl; 
    }
}

int linkedlist::get_length()
{
    return length;
}

linkedlist::~linkedlist()
{
    node *p = head;
    while(p->next != NULL)
    {
        head = p->next;
        delete(p);
	p = head;
    }
        	
}
