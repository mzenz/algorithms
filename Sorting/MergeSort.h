#pragma once

#include <vector>

template<class T>
void merge(std::vector<T>& a, std::vector<T>& aux, size_t lo, size_t mid, size_t hi)
{
  for (size_t k = lo; k <= hi; ++k)
    aux[k] = a[k];

  size_t i = lo;
  size_t j = mid + 1;
  for (size_t k = lo; k <= hi; ++k) {
    if (i > mid)              a[k] = aux[j++];
    else if (j > hi)          a[k] = aux[i++];
    else if (aux[j] < aux[i]) a[k] = aux[j++];
    else                      a[k] = aux[i++];
  }
}

// O(N) = N lg N
// NOTE: non-recursive merge sort is called bottom-up merge sort
template<class T>
void mergeSort(std::vector<T>& v)
{
  std::vector<T> aux(v.size());
  for (size_t sz = 1; sz < v.size(); sz *= 2) {
    for (size_t lo = 0; lo < v.size() - sz; lo += sz + sz) {
      merge(v, aux, lo, lo + sz - 1, std::min(lo + sz + sz - 1, v.size() - 1));
    }
  }
}

template<class T>
void sortRecursive(std::vector<T>& v, std::vector<T>& aux, size_t lo, size_t hi)
{
  if (lo >= hi) return;

  const size_t mid = lo + (hi - lo) / 2;
  sortRecursive(v, aux, lo, mid);
  sortRecursive(v, aux, mid + 1, hi);
  merge(v, aux, lo, mid, hi);
}

template<class T>
void mergeSortRecursive(std::vector<T>& v)
{
  std::vector<T> aux(v.size());
  sortRecursive(v, aux, 0, v.size() - 1);
}
