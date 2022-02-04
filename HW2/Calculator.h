#ifndef __CALCULATOR__
#define __CALCULATOR__

#include "Stack.h"
#include <sstream>  
#include <string>

class Calculator {
private:  
	Stack* stack; // pointer that will be used in Calculator
	string postfixExpression; // converted postfix expression
	string infixExpression; // the input that will be converted to postfix expression
public:  
	Calculator(string); // contructor holding string infixExpression
	string getPostfix(); // method that returns postfix expression
	int calculate(); // method to calculate mathematical value of infix expression
	~Calculator(); // deconstructor
};

#endif