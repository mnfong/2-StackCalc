#include <iostream>
#include <stdio.h>
#include <string.h>
#include "dstack.h"

using namespace std;

int main()
{
  // variables used throughout the program
  string equation;
  double value = 0;
  Dstack numbers;
  string holder = "";
  char c;
  double lval = 0;
  double rval = 0;
  double answer = 0;
  bool isAdded = false;

  // iterates through the equation
  while (cin.get(c))
  {

    // checks if the next character is a space
    if (isspace(cin.peek()))
    {
      if (isdigit(c))
      {
        if (!isAdded)
          holder += c;

        value = stod(holder);
        numbers.push(value);
        isAdded = false;
      }
      cin.ignore();
      holder = "";
    }
    // checks if the character is a number
    else if ((isdigit(c)) || (c == '.'))
    {
      holder += c;

      if ((c == '.') && (isdigit(cin.peek())))
      {
       char nextChar = cin.peek();
       holder += nextChar;
       isAdded = true;
      }

      value = stod(holder);

      // checks if the next character is an operator
      if ((cin.peek() == '+') || (cin.peek() == '-') || (cin.peek() == '*') || (cin.peek() == '/' || (cin.peek() == '^')))
      {
        numbers.push(value);
      }
    }

    if ((numbers.size() > 1) && ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')))
    {
      if ((numbers.pop(rval)) && (numbers.pop(lval)))
      {
        switch(c)
        {
          case '+': answer = lval + rval;
                    break;

          case '-': answer = lval - rval;
                    break;

          case '*': answer = lval * rval;
                    break;

          case '/': answer = lval / rval;
                    break;

          case '^': answer = lval;
                    if (rval == 0)
                      answer = 1;
                    else if (rval > 1)
                    {
                      for (int count = 2; count <= rval; count++)
                      {
                        answer = answer * lval;
                      }
                    }
                    break;
          default: cerr << "Error: Invalid expression." << endl;
                   return 1;
        }
        numbers.push(answer);
      }
    }
    else if (!(numbers.size() > 1) && ((c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^')))
    {
      cerr << "Error: Invalid expression." << endl; 
      return 1;
    }
  }

  // checks the size of the stack
  if (numbers.size() == 1)
  {
    numbers.pop(value);
    answer = value;
  }

  // checks to see if there is more than 1 value in the stack
  if (numbers.size() > 1)
  {
    cerr << "Error: Invalid expression." << endl;
    return 1;
  }
  cout << answer << endl;
  return 0;
}
