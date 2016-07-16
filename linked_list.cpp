#include<iostream>
using namespace std;

struct node{
        int data;
        node* next;
};

//node* head = NULL;
//int count = 0;
int size(node**);

void insert(node** head, int d, int pos){
        int si = size(head);
        if (pos > si + 1){
                cout << "Invalid position" << endl;
                return;
        }
        node* temp = new node();
        temp->data = d;
        if (pos == 1){
                temp->next = *head;
                *head = temp;
                return;
        }
        node *temp2 = *head;
        for (int i = 0; i < pos-2; i++){
                temp2 = temp2->next;
        }
        temp->next = temp2->next;;
        temp2->next = temp;
}

void del(node** head, int pos){
        int si = size(head);
        if(pos > si + 1){
                cout << "Invalid position" << endl;
                return;
        }
        node* temp = *head;
        if(pos == 1){
                *head = temp->next;
                delete(temp);
        }
        for(int i=0; i<pos-2;i++){
                temp = temp->next;
        }
        node* temp2 = temp->next;
        temp->next = temp2->next;
        delete(temp2);
}

void print(node** head){
        node* temp =*head;
        cout<<"The list is ";
        while(temp!=NULL){ cout<<temp->data<<" "; temp = temp->next;}
        cout<<endl;}

int size(node** h){
        int count = 0;
        node* temp = *h;
        while(temp!=NULL){ temp = temp->next; ++count; }
        cout << endl <<"Size is "<<count<<" ";
        return count;
}

void reverse(node** head){
        cout << "================= Reversing the linked list ======================" << endl;
        node *prev, *current, *next;
        prev = NULL;
        current = *head;
        while(current != NULL){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
        }
        *head = prev;
}

void print_recursive(node *head){
        node *p = head;
        if(p==NULL){ return; }
        cout << p->data;
        print_recursive(p->next);
}

void print_reverse_recursive(node *head){
        node *p = head;
        if (p == NULL){ return;}
        print_reverse_recursive(p->next);
        cout << p->data;
}

void reverse_list_recursive(node *head){
	node *p = head;
        if (p->next == NULL){ head = p; return; }
        reverse_list_recursive(p->next);
        p->next->next = p;
        p->next = NULL;
}

int main(){
        node* head = NULL;
        print(&head);
        insert(&head, 1,1);
        print(&head);
        insert(&head,2,2);
        print(&head);
        insert(&head,3,3);
        print(&head);
        insert(&head,6,2);
        print(&head);
        del(&head, 3);
        cout<<"printing recursive";
        print_recursive(head);
        cout<<endl<<"printing in reverse - recursive "<< endl;
        print_reverse_recursive(head);
        reverse(&head);
        print(&head);
        cout << " Reversing using recursion"<< endl;
        reverse_list_recursive(head);
        print(&head);
}

