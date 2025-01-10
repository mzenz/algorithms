#pragma once

#include <vector>
#include <cassert>
#include <unordered_map>

template<class T>
std::vector<T> findTopK(const std::vector<T>& a, size_t k) {
  assert(k < a.size() && "k is larger than input array size you dummy!");

  std::unordered_map<T, size_t> count;
  std::vector<std::vector<T>> freq(a.size() + 1);
  std::vector<T> topK;
  topK.reserve(k);

  for (auto i = 0; i < a.size(); ++i) {
    ++count[a[i]];
  }

  for (auto it = count.begin(); it != count.end(); ++it) {
    freq[it->second].push_back(it->first);
  }

  for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
    for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
      topK.push_back(*it2);
      if (topK.size() == k)
        return topK;
    }
  }

  return topK;
}
