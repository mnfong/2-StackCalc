// dstack.cpp
// Fong, Madison
// mnfong

#include <iostream>
#include "dstack.h"

using namespace std;

// inital constructor
Dstack::Dstack()
{
  top = NULL;
  m_length = 0;
}

// deconstructor
Dstack::~Dstack()
{
  while (top != NULL)
  {
    Node *tmp = top;
    top = top -> m_next;
    delete tmp;
  }
}

// pushes a new number to the top of the stack
void Dstack::push(double number)
{
  top = new Node(number, top);
  m_length++;
}

// prints out each number in the stack
void Dstack::print()
{
  if (top == NULL)
    return;
  for (Node *ptr = top; ptr; ptr = ptr -> m_next)
  {
    cout << ptr -> m_value << " ";
  }
  cout << endl;
}

// deletes the top number from the stack and returns its value
bool Dstack::pop(double &value)
{
  if (m_length == 0)
    return false;
  value = top -> m_value;
  Node *oldTop = top;
  top = top -> m_next;
  m_length--;
  delete oldTop;
  return true;
}

// returns true if the list is empty
bool Dstack::empty()
{
  return (m_length == 0);
}

// returns the size of the stack
int Dstack::size()
{
  return m_length;
}
