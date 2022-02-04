#ifndef _Stack_
#define _Stack_

#include "StackItem.h"

class Stack {
protected:
	StackItem *head;
public:
	Stack(); // constructor for Stack structor
	void push(StackItem*); // insertion of an StackItem element to the top
	StackItem* pop(); // removal of the element at the top
	StackItem* top(); // return the element on top
	virtual bool isEmpty(); // returns true if the stack is empty
	~Stack(); // deconstructor
};

#endif