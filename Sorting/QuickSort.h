#pragma once

#include "Shuffle.h"
#include <vector>

template<class T>
int partition(std::vector<T>& v, int lo, int hi)
{
  int i = lo, j = hi+1;
  while (true) {
    while (v[++i] < v[lo])
      if (i == hi)
        break;

    while (v[lo] < v[--j])
      if (j == lo)
        break;

    if (i >= j)
      break;
    std::swap(v[i], v[j]);
  }

  std::swap(lo, j);
  return j;
}

template<class T>
void sort(std::vector<T>& a, int l, int r)
{
  int i = l-1, j = r, p = l-1, q = r;
  auto v = a[r];
  if (r <= l)
    return;

  while (true)
  {
    while (a[++i] < v);

    while (v < a[--j])
      if (j == l)
        break;

    if (i >= j)
      break;
    std::swap(a[i], a[j]);
    if (a[i] == v) { p++; std::swap(a[p], a[i]); }
    if (v == a[j]) { q--; std::swap(a[j], a[q]); }
  }
  std::swap(a[i], a[r]);
  j = i-1;
  i = i+1;
  for (auto k = l; k < p; k++, j--)
    std::swap(a[k], a[j]);
  for (auto k = r-1; k > q; k--, i++)
    std::swap(a[i], a[k]);
  sort(a, l, j);
  sort(a, i, r);
}

// O(N) = N lg N
// average complexity ~ 1.39*N*lg(N)
// Faster than mergesort mainly because it doesn't have to copy things to an aux array but instead increments pointers
template<class T>
void quickSort(std::vector<T>& v)
{
  //
  shuffle(v);
  sort(v, 0, (int)v.size() - 1);
}
