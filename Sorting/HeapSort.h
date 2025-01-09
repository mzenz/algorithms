#pragma once

#include "Shuffle.h"
#include <vector>

template<typename T>
void swim(std::vector<T>& v, size_t i)
{
  for (size_t p = (i - 1) / 2; i > 0 && v[i] > v[p]; i = p, p = (i - 1) / 2) {
    std::swap(v[i], v[p]);
  }
}

template<typename T>
void sink(std::vector<T>& v, size_t i, size_t size)
{
  size_t j = 2 * i + 1;
  while (j < size) {
    // pick i's greatest child (if there are more than one)
    if (j + 1 < size && v[j + 1] > v[j]) {
      ++j;
    }
    if (v[i] >= v[j]) {
      break;
    }
    std::swap(v[i], v[j]);
    i = j;
    j = 2 * i + 1;
  }
}

// NOTE: v is interpreted as a zero-based binary heap, having its root at v[0]
// child(i) = { 2i+1 , 2i+2 }
// parent(i) = (i-1)/2
template<typename T>
void heapSort(std::vector<T>& v) {
  // first pass: sink everything starting from lowest parent
  // all the way to the root (this is fucking genius)
  // NOTE: O(N) = 2N  ---> PRETTY SWEET!
  for (size_t i = (v.size() - 2) / 2; (i + 1) > 0; --i) {
    sink(v, i, v.size());
  }

  // second pass:
  // - Swap greatest element (i.e. the root) with last the element
  // - Leave greatest element (just swapped to the bottom of the heap) and sink
  //   new root as if the heap just shrunk by 1 (this way all biggest elements
  //   stay ordered at the end)
  for (size_t i = v.size() - 1; i > 0; --i) {
    std::swap(v[0], v[i]);
    sink(v, 0, i);
  }
}
