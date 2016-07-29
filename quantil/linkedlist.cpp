#include "linkedlist.h"

linkedlist::linkedlist(){
    head = tail = NULL;
    length = 0;
}

void linkedlist::insert_node(node *newnode){
    node* temp = newnode;
    temp->next = NULL;
    if (head == NULL){
	temp->next = head;
	head = temp;
	tail = temp;
        length++;
        return;
    }
    tail->next = temp;
    tail = temp;
    length++;
}

/*bool linkedlist::remove_node( string node_key ){
    if (head->next) return false;
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
}*/

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

/*linkedlist::~linkedlist()
{
    if (head != NULL){
    node *temp = head;
    while(temp != NULL)
    {
        head = temp->next;
        delete(temp);
	temp = head;
    }
}
        	
}*/
