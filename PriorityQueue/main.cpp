#include <iostream>
#include "binary_heap.h"
#include "binary_heap_1_based.h"

int main(int argc, const char *argv[])
{
    //  binary_heap_1_based<char> h;
  binary_heap<char> h;
  h.push('S');
  h.push('O');
  h.push('R');
  h.push('T');
  h.push('E');
  h.push('X');
  h.push('A');
  h.push('M');
  h.push('P');
  h.push('L');
  h.push('E');

  std::cout << "Heap before:" << std::endl;
  h.print();
  std::cout << std::endl;

  while (!h.empty()) {
    std::cout << h.pop() << " ";
  }

  std::cout << std::endl;
}
