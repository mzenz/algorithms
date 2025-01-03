#pragma once

#include <vector>

template<class T>
void merge(std::vector<T>& a, std::vector<T>& b, size_t lo, size_t mid, size_t hi)
{
  for (size_t k = lo; k <= hi; ++k)
    b[k] = a[k];

  size_t i = lo;
  size_t j = mid + 1;
  for (size_t k = lo; k <= hi; ++k) {
    if (i > mid)             a[k] = b[j++];
    else if (j > hi)         a[k] = b[i++];
    else if (b[j] < b[i])    a[k] = b[j++];
    else                     a[k] = b[i++];
  }
}

// O(N) = N lg N
template<class T>
void mergeSort(std::vector<T>& v)
{
  std::vector<T> aux(v.size());
  for (size_t sz = 1; sz < v.size(); sz *= 2) {
    for (size_t lo = 0; lo < v.size() - sz; lo += sz + sz) {
      merge(v, aux, lo, lo + sz - 1, std::min(lo + sz + sz - 1, v.size() - 1));
    }
  }
};
