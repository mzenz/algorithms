#include <iostream>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

template<class K, class T>
bool validateBST(const BinarySearchTree<K,T>& tree)
{
  vector<K> v(tree.size());
  size_t i = 0;
  for (auto it = tree.begin(); it.valid(); ++it, ++i) {
    cout << *it.key() << ", ";
    v[i] = *it.key();
  }

  if (i != tree.size()) {
    cout << "BST error, iterated " << i << " elements, tree size = " << tree.size() << endl;
    return false;
  }
  cout << endl;

  auto sorted = is_sorted(v.begin(), v.end());
  cout << (sorted? "BST is OK" : "BST ERROR") << endl;
  return sorted;
}

void test()
{
  typedef BinarySearchTree<char, string> BST;

  BST t { {'D', "d"},
      {'A', "a"},
      {'B', "b"},
      {'C', "c"},
      {'X', "x"},
      {'R', "r"}};

  auto v = t.get('C');
  cout << "v = " << (v ? *v : "null")<< endl;
  auto min = t.min();
  auto max = t.max();
  cout << "min = " << (min ? *min : "null")<< endl;
  cout << "max = " << (max ? *max : "null")<< endl;

  cout << "forward order: ";
  for (auto it = t.begin(); it.valid(); ++it)
    cout << *it.value() << ", ";
  cout << endl;

  cout << "reverse order: ";
  for (auto it = t.rbegin(); it.valid(); ++it)
    cout << *it.value() << ", ";
  cout << endl;
}

void testReverseIterator()
{
  typedef BinarySearchTree<int,int> BST;
  BST t;
  srand((int)time(nullptr));
  for (auto i = 0; i < 32; ++i) {
    auto r = 100 * (float)rand() / RAND_MAX;
    t.put(r, r);
  }

  vector<BST::KeyType> v(t.size());
  auto i = 0;
  for (auto it = t.rbegin(); it.valid(); ++it, ++i)
    v[i] = *it.key();

  assert(is_sorted(v.begin(), v.end(), greater<int>()));
}

void testForwardIterator()
{
  typedef BinarySearchTree<int,int> BST;
  BST t;
  srand((int)time(nullptr));
  for (auto i = 0; i < 32; ++i) {
    auto r = 100 * (float)rand() / RAND_MAX;
    t.put(r, r);
  }

  assert(validateBST(t));
}

void testRBT()
{
  typedef RedBlackTree<int,int> RBT;
  RBT t;
  srand((int)time(nullptr));
  for (auto i = 0; i < 32; ++i) {
    auto r = 100 * (float)rand() / RAND_MAX;
    t.put(r, r);
  }

  vector<RBT::KeyType> v(t.size());
  auto i = 0;
  for (auto it = t.begin(); it.valid(); ++it, ++i)
    v[i] = *it.key();

  assert(is_sorted(v.begin(), v.end()));
}

void testRemoveKey()
{
  typedef BinarySearchTree<int,int> BST;
  BST t { 1,3,8,7,5,6,4,2,9 };

  assert(validateBST(t));

  auto size = t.size();

  t.erase(3); --size;
  t.erase(9); --size;
  t.erase(7); --size;

  assert(validateBST(t));
}

int main(int argc, const char * argv[])
{
//  test();
//  testForwardIterator();
//  testReverseIterator();
//
//  testRBT();

  testRemoveKey();
}
