// dstack.h
// Fong, Madison
// mnfong

#include <iostream>
#ifndef DSTACK_H
#define DSTACK_H

using namespace std;

class Dstack
{
  // public functions that the stack uses
  public:
    Dstack();
    ~Dstack();

    void push(double number);
    bool pop(double &value);
    bool empty();
    void print();
    int size();

  // private function that builds the linked list for the stack
  private:
    class Node
    {
      public:
        Node(double value, Node *next)
        {
          m_value = value; m_next = next;
        }
        double m_value;
        Node *m_next;
    };
    Node *top;
    int m_length;
};

#endif
