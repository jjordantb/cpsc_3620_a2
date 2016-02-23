/*
 * To compile:
 * Ensure your working directory contains this file
 * Then run: <compiler_name> -o Fib Fib.cc
 * The executable is "Fib"
 */

#include <iostream>
#include <stack>

using namespace std;

long fib(int);

int main()
{

  cout << "Enter value: "
  long val;
  cin >> val;
  cout << "Fib: " << fib(val) << endl;

  return 0;
}

long fib(int x)
{
  if (x > 46)
  {
    return -1;
  }

  int cnt = 0;
  stack<long> stack;
  stack.push(1);
  stack.push(1);
  while (!stack.empty() && cnt < x - 2)
  {
    long tmp1 = stack.top();
    stack.pop();
    long tmp2 = stack.top();
    stack.pop();
    long tmp3 = tmp1 + tmp2;
    stack.push(tmp2);
    stack.push(tmp1);
    stack.push(tmp3);
    cnt++;
  }
  return stack.top();
}
