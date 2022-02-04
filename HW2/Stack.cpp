#include "Stack.h"

using namespace std;

Stack::Stack() {
	head = 0;
}

void Stack::push(StackItem *item) { // insert an element to the top
	if (!isEmpty()) {  
		item->next = head;
		head = item;
	}
	else { // assign head as item if stack is empty
		head = item;
		item->next = 0;
	}
}

StackItem* Stack::pop() {
	StackItem* item_ = head; // create a pointer that equals head
	if (!isEmpty()) { // implement linked list if the stack is not empty
		head = item_->next;
		return item_;
	}
	else // otherwise remove the element 
		return 0;
}

StackItem* Stack::top() { // returning without removing the element on top
	return head;	}

bool Stack::isEmpty() { // return head variable as 0 if the stack is empty
	return head == 0;	
}

Stack::~Stack() {
	while (!isEmpty()) // deletes the element if particular address isn't empty
		delete pop();
}