#pragma once

#include <vector>
#include <cassert>
#include "InsertionSort.h"

void bucketSort(std::vector<double>& v)
{
  std::vector<std::vector<double>> buckets(v.size());

  for (auto i = 0; i < v.size(); ++i) {
    const auto n = v[i];
    assert(0 <= n && n < 1);

    const size_t k = n * v.size();
    buckets[k].push_back(n);
  }

  for (auto i = 0; i < buckets.size(); ++i) {
    insertionSort(buckets[i]);
  }

  for (auto i = 0, k = 0; i < buckets.size(); ++i) {
    for (auto j = 0; j < buckets[i].size(); ++j) {
      v[k] = buckets[i][j];
      ++k;
    }
  }
}
