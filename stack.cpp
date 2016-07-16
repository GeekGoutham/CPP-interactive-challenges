#include<iostream>
using namespace std;

class stack{
public:
	int data;
	stack *next;
};

class stack_list{

	stack *top;
public:
	stack_list(): top(NULL){};
	
	void push(int d){
		stack *node = new stack();
		node->data = d;
		node->next = top;
		top = node;
	}
	
	void pop(){
		stack *node = top;
		top = top->next;
		delete(node);
	}

	int tp(){
		return top->data;
	}

	bool isEmpty(){
		return (top? true : false);
	}
	
	void print(){
		cout << "The Stack is ";
		for(stack *curr = top; curr!=NULL; curr=curr->next){	
			cout << " " << curr->data;
		}
		cout <<endl;
	}

};

int main(){
	
	stack_list s;
	s.push(1);s.print();
	s.push(2);s.print();
	s.push(3);s.print();
	s.push(4);s.print();
	s.pop();s.print();
	cout << s.tp(); s.print(); 
	cout << s.isEmpty()<<endl;
}
