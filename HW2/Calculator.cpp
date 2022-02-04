#include "Calculator.h" 
#include <ctime>

using namespace std;

Calculator::Calculator(string infixExpression) { 
	// this method writes infix as postfix form
	clock_t start1 = clock();
	stack = new Stack();
	istringstream iss(infixExpression);
	string temp;
	iss >> temp;

	while (temp.compare(";") != 0) { 
		StackItem* items = new StackItem(temp);	
		// ^ array that accepts operands and operators
		if (!items->isOperator) // if element is not an operator
			postfixExpression += temp + " "; // insert for temp variable
		
		else if (items->op == 1) { // if it is right-paranthesis
			while (stack->top()->op != 0)
				postfixExpression += (stack->pop())->toString() + " ";

			stack->pop(); // pop it from stack
		}
		
		else if (items->op == 0) // if it is right-paranthesis
			stack->push(items); // push it into stack
		
		else { // do mathematical operations if operator varies from 2 to 5
			if (items->op == 2) { // if it is minus
				while (!stack->isEmpty() && stack->top()->op != 0)
					postfixExpression += (stack->pop())->toString() + " "; 
					// ^ adjust its position as postfix form
			}

			else if (items->op == 3) { // if it is plus
				while (!stack->isEmpty() && stack->top()->op != 0)
					postfixExpression += (stack->pop())->toString() + " ";
				// ^ adjust its position as postfix form
			}

			else { // if it is division or multiplication
				if (!stack->isEmpty() && stack->top()->op != 0 && stack->top()->op == 4) {
					while (!stack->isEmpty() && stack->top()->op == 4  && stack->top()->op != 0)
						postfixExpression += (stack->pop())->toString() + " ";
					// ^ adjust its position as postfix form
				}

				clock_t start3 = clock();
				for (int i = 0; i <= 100; i++) // implementation of runtime calculation
					for (int j = 0; j <= 100; j++) {
						double t = 0;
						t++;
					}
				clock_t end3 = clock();
				double cpu_time1 = static_cast<double>(end3 - start3) / CLOCKS_PER_SEC;

				if (!stack->isEmpty() && stack->top()->op != 0 && stack->top()->op == 5) {
					while (!stack->isEmpty() && stack->top()->op == 5 && stack->top()->op != 0)
						postfixExpression += (stack->pop())->toString() + " ";
					// ^ adjust its position as postfix form
				}
			}
			stack->push(items);
		}
		iss >> temp;
	}
	while (!stack->isEmpty()) 
		postfixExpression += (stack->pop()->toString()) + " ";

	postfixExpression += ";"; // insertion of ";" to conclude the expression

	clock_t end1 = clock();
	double cpu_time1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
	// ^ calculates the time by subtracting end and beginning time variables
	double cpu_time2 = cpu_time1 * 1000; // time of milliseconds

	cout << "Computation time: " << cpu_time2 << " millisecond(s)" << endl;
	
}


string Calculator::getPostfix() {
	return postfixExpression;
}


int Calculator::calculate() { // calculate the value of input by using variable -stack-
	clock_t start2 = clock(); 

	stack = new Stack();
	int output = 0; 
	string temp_;
	istringstream iss_(postfixExpression);
	iss_ >> temp_;
	while (temp_.compare(";") != 0) {
		StackItem* opr_item = new StackItem(temp_);
		if (!opr_item->isOperator)
			stack->push(opr_item);
		
		else {
			int x = stack->pop()->n; // first operand
			int y = stack->pop()->n; // second operand 

			if (opr_item->op == 2) // subtract if the operator is OPERATOR_MINUS
				output = y - x;
			if (opr_item->op == 3) // add if the operator is OPERATOR_PLUS
				output = y + x;
			if (opr_item->op == 4) // divide if the operator is OPERATOR_DIVISION
				output = y / x;
			if (opr_item->op == 5) // divide if the operator is OPERATOR_MULTIPLICATION
				output = y * x;

			StackItem* result = new StackItem(0, output);
			stack->push(result);
		}
		iss_ >> temp_; // to reset infix expression
	}
	output = stack->pop()->n;
	
	clock_t end2 = clock();
	
	double cpu_time1 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
	// ^ calculates the time by subtracting end and beginning time variables
	double cpu_time2 = cpu_time1 * 1000; // time of milliseconds
	// cout << "Computation time: " << cpu_time2 << " millisecond(s)" << endl;

	return output;
}


Calculator::~Calculator() { // deconstructor to delete stack variable
	delete[] stack;
	cout << "The postfix expression is deleted." << endl;
}


