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


void linkedlist::print_list(){

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

int linkedlist::get_length(){

    return length;
}
