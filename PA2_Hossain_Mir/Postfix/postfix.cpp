/*Mir Hossain
CS302
Proj2: postfix.cpp
*/

/*
This was not the most efficient way to do this project. A better solution would have been
to do everything in one function considering that both my conversion and solve
functions follow a similar method. I didn't want to break my entire program so I
just made a seperate function for the expression solver. The program works for the most part
but if 'end' is the first thing entered by the user a bunch of random values show
up on the screen
*/
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <math.h>



/*
Function precedence: This function will check which operator comes first. I
control which operator takes precedence by returning values.
*/
double precedence(char checkOperator){

  if(checkOperator == '^')
    return 4;
  else if(checkOperator == '*' || checkOperator == '/')
    return 3;
  else if(checkOperator == '+' || checkOperator == '-')
    return 2;
  else
    return 1;
}

/*
Function applyOperation: Just applies the operations
*/
double applyOperation(double valueOne, double valueTwo, char operation){

  switch(operation){
    case '^': return pow(valueOne, valueTwo);
    case '+': return valueOne + valueTwo;
    case '-': return valueOne - valueTwo;
    case '*': return valueOne * valueTwo;
    case '/': return valueOne / valueTwo;
    }
}

/*
Function convertPostfix: This function will take care of converting the infix
to postfix.
*/
void convertPostfix(std::string input){

  std::stack<char> dataStack;
  std::string output;
  int stringLen = input.length();

  dataStack.push('A'); //This is pushing a temp value onto the dataStack

  //Traverse the string
  for(int i = 0; i < stringLen; i++){

    if(input[i] == ' '){ //Skip whitespace
      continue;
    }

    else if((input[i] >= '0' && input[i] <= '9')){ //Establish bounds
      output+=input[i]; //inputs everything into output
    }
    else if(input[i] == '('){ //Parens come first, so push it to Stack
      dataStack.push('(');
    }

    else if(input[i] == ')'){ //If a ')' is detected then keep popping off till
                              // a '(' is found
      while(!dataStack.empty() && dataStack.top() != '('){
        char beforeParens = dataStack.top(); //Values is used as a output
        dataStack.pop();
        output += beforeParens;
        }

      if(dataStack.top() == '('){
        char afterParens = dataStack.top();
        dataStack.pop();
        //output += afterParens;
        }
      }

    else{ //Checking for an operator
      while(!dataStack.empty() && precedence(input[i]) <= precedence(dataStack.top())){ //Checking if past output and before the top of stack
                                                                                            //using the return values from precedence function
			 char operators = dataStack.top();
				dataStack.pop();
				output += operators;
		    }
		dataStack.push(input[i]);
      }
    }

  	while(dataStack.top() != 'A') //This just pops everything else that wasn't accounted for prior
  	{
  		char values = dataStack.top();
  		dataStack.pop();
  		output += values;
  	}

    std::cout << output << std::endl;
}

/*
Function solveExpression: This function will solve the expression using a similar
approach used in function convertPostfix
*/
void solveExpression(std::string input){

  std::stack<double> operands;
  std::stack<char> operators;
  int stringLen = input.length();

  for(int i = 0; i < stringLen; i++){ //Traverse

    if(input[i] == ' '){ //Skip whitespace
      continue;
    }

    else if(input[i] == '('){ //Check if opening paren
            operators.push(input[i]);
    }

    else if(isdigit(input[i])){ //Check if theres a number then pushes it onto the operand stack
			double value = 0;
			value = value + (input[i]-'0'); //Not sure why -0 is needed, but I was getting crazy values without it
			operands.push(value);
		}

    //solve everything before the ')' is detected
    else if(input[i] == ')'){
			while(!operators.empty() && operators.top() != '('){
				double value2 = operands.top();
				operands.pop();

				double value1 = operands.top();
				operands.pop();

				char operatoroutput = operators.top();
				operators.pop();

				operands.push(applyOperation(value1, value2, operatoroutput));
		    }
			operators.pop(); //pop '('
    }

    //Check and take care of operators
    else{
      while(!operators.empty() && precedence(operators.top()) >= precedence(input[i])){
        double value2 = operands.top();
				operands.pop();

				double value1 = operands.top();
				operands.pop();

				char operatoroutput = operators.top();
				operators.pop();

				operands.push(applyOperation(value1, value2, operatoroutput));
        }
        operators.push(input[i]); //push current into operator stack
    }
  }

  //Take care of everything that wasn't taken care of prior
  while(!operators.empty()){
    double value2 = operands.top();
    operands.pop();

    double value1 = operands.top();
    operands.pop();

    char operatoroutput = operators.top();
    operators.pop();

    operands.push(applyOperation(value1, value2, operatoroutput));
  }
  std::cout << operands.top();
   //The soultion of the expression should be stored at the top of the stack
}

int main(){

  std::string input;
  std::string terminate = "end";
  std::transform(terminate.begin(), terminate.end(), terminate.begin(),::toupper); //Extra stuff makes it not case sensitive


  std::cout << "This program converts infix to postfix notation and solves the expression" << std::endl << "Enter 'end' to close the program" << std::endl;

  do{
  //  if(input 'a')
  std::cout << std::endl;
  std::cout << "Enter Expression: ";
  std::cin >> input;

  std::cout << "Conversion to Postfix: ";
	convertPostfix(input);

  std::cout << "Solution to Expression: ";
  solveExpression(input);
  std::cout << std::endl << std::endl;

  }

  while(input != terminate);
	return 0;

}
