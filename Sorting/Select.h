#pragma once

#include "QuickSort.h"

template<class T>
size_t select(std::vector<T>& v, size_t k)
{
  shuffle(v);
  int lo = 0, hi = (int)v.size() - 1;
  while (hi > lo) {
    int j = partition(v, lo, hi);
    if      (j < k) lo = j+1;
    else if (j > k) hi = j-1;
    else            return v[k];
  }
  return v[k];
}
