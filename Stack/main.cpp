#include <iostream>
#include "Stack.h"

// Sieve of Eratosthenes algorithm
int main(int argc, const char * argv[])
{
  Stack<int> s;
  s.push(4);
  s.push(2);
  s.push(0);

  for (; s.size() > 0;) {
    std::cout << s.pop() << std::endl;
  }
}
