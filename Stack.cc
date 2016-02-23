/*
 * To compile:
 * Ensure your working directory contains this file
 * Then run: g++ -o Stack Main.cc
 * The executable is Stack
 */

#include <iostream>
#include <stack>
#include <assert.h>
#include <string>

#ifndef ASTACK_H
#define ASTACK_H

class AStack: public std::stack<char>
{

private:
  int maxSize; // Maximum size of stack
  int i_top; // Index for top element
  char *listArray; // Array holding stack elements

public:
  AStack(int size) // Constructor
  {
    maxSize = size; i_top = 0;
    listArray = new char[size];
  }
  ~AStack()
  {
    delete [] listArray;
  } // Destructor

void clear()
{
  i_top = 0;
} // Reinitialize

void push(const std::string& it)
{
  assert(it.size() <= 256);
  assert(i_top + it.size() + 1 <= maxSize);
  for (size_t i = 0; i < it.size(); i++) {
    listArray[i_top++] = it[i];
  }
  listArray[i_top++] = (char) it.size();
}

std::string pop()
{ // Pop top element
  assert(i_top != 0);
  int size = ((int) listArray[--i_top]);
  std::string str = "";
  for (size_t i = 0; i < size; i++) {
    str = listArray[--i_top] + str;
  }
  return str;
}

const int top() const
{ // Return top element
  assert(i_top != 0);
  return ((int)listArray[i_top-1]);
}

int length() const
{
  return i_top - 1;
} // Return length

};

#endif // SSTACK_H

int main()
{

  AStack stack(1000);
  stack.push("kappa");
  stack.push("jordan");
  stack.push("nugget");
  stack.push("cat");

  // Triggers Assertion for maxSize
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");
  // stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");

  // Triggers Assertion for string > 255
  //stack.push("cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_cpsc_3620_");

  while (stack.length() > 0) {
    std::cout << stack.pop() << std::endl;
  }

  return 0;
}
