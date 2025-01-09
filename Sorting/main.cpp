#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "BucketSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Select.h"
#include <iostream>
#include <algorithm>
#include <cassert>

template<class T>
void print(const std::vector<T>& v)
{
  for(auto d : v) {
    std::cout << d << " ";
  }
  std::cout << std::endl;
}

int main(int argc, const char * argv[])
{
  // std::vector<double> v { .22, .23, .54, .91, .14, 0.03, .66, .01, .9, .24 };
  std::vector<char> v { 'S','O','R','T','E','X','A','M','P','L','E' };

  std::cout << "before:\n";
  print(v);

  // selectionSort(v);
  // insertionSort(v);
  // shellSort(v);
  // mergeSortRecursive(v);
  // mergeSort(v);
  // quickSort(v);
  heapSort(v);
  // bucketSort(v);

  // std::sort(v.begin(), v.end());
  // std::stable_sort(v.begin(), v.end());

  const bool isSorted = std::is_sorted(v.begin(), v.end());

  std::cout << "\nafter:\n";
  print(v);
  std::cout << "\nsorted? " << (isSorted ? "YES" : "NOPE") << std::endl;
  assert(isSorted);

  return 0;
}
