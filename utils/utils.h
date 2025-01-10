#pragma once

#include <iostream>
#include <vector>

template<class T>
void printVector(const std::vector<T>& a) {

  std::cout << "[";
  for (auto i = 0; i < a.size(); ++i) {
    std::cout << a[i];
    if (i < a.size() - 1)
      std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}
