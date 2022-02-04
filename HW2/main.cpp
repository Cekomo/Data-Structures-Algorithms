//============================================================================
// Name        : main.cpp
// Author      : Hasan Sozer
// Version     : 1.1
// Copyright   : (c) 2012 Ozyegin University
// Description : Includes the main function that will be used as part of the
//               program to be submitted as Homework 2, which is assigned in the 
//               context of the course CS201, Data Structures and Algorithms.
//				 Asks for an arithmetic expression from the user in infix form.
//				 Prints out the expression in postfix form, evaluates the 
//				 expression and also prints out the result.
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include "Calculator.h"

int main ()
{
	string infixExpression;
	cout << "Enter an arithmetic expression:" << endl;
	getline(cin, infixExpression);

	Calculator* intopost = new Calculator(infixExpression);
	// ^ instantiation of an array that holds values from Calculator

	cout << "Input expression in postfix form: " << intopost->getPostfix() << endl;
	// ^ takes postfix expression from Calculator class
	cout << "The result is: " << intopost->calculate() << endl;
	// ^ takes result from Calculator class

	delete intopost; // delete the variable to prevent memory leak
  
	return 0;
}
