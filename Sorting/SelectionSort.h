#pragma once

#include <vector>

template<class T>
void selectionSort(std::vector<T>& v)
{
  for (size_t i = 0; i < v.size(); ++i) {
    size_t min = i;
    for (size_t j = i + 1; j < v.size(); ++j) {
      if (v[j] < v[min]) // compare
        min = j;
    }
    std::swap(v[i], v[min]); // exchange
  }
};
