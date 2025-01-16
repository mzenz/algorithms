#pragma once

// Dialpad interview exercise, round 2
// Merge two sorted integer-containing linked list
// Return a merged linked list containing integers from both lists in sorted order

// Example
// A = 1 -> 3 -> 5
// B = 2 -> 4 -> 6
// C
// expected_result = 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Merge N sorted linked lists

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Merges a with b, with b as input + output
// O(N + M)
void mergeInPlace(const list<int> &a, list<int> &b)
{
  auto itA = a.begin();
  auto itB = b.begin();
  for (; itA != a.end() && itB != b.end();) {
    auto va = *itA;
    auto vb = *itB;
    if (va < vb) {
      b.insert(itB, va);
      itA++;
    } else {
      itB++;
    }
  }
  for (; itA != a.end(); ++itA) {
    b.push_back(*itA);
  }
}

// O(N * M)
void mergeListsInPlace(const vector<list<int>> &v, list<int>& out) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    mergeInPlace(*it, out);
  }
}
