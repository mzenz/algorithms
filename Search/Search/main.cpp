#include <iostream>
#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>

using namespace std;

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
        t.insert(r, r);
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
        t.insert(r, r);
    }
    
    vector<BST::KeyType> v(t.size());
    auto i = 0;
    for (auto it = t.begin(); it.valid(); ++it, ++i)
        v[i] = *it.key();
    
    assert(is_sorted(v.begin(), v.end()));
}

void testRBT()
{
    typedef RedBlackTree<int,int> RBT;
    RBT t;
    srand((int)time(nullptr));
    for (auto i = 0; i < 32; ++i) {
        auto r = 100 * (float)rand() / RAND_MAX;
        t.insert(r, r);
    }
    
    vector<RBT::KeyType> v(t.size());
    auto i = 0;
    for (auto it = t.begin(); it.valid(); ++it, ++i)
        v[i] = *it.key();
    
    assert(is_sorted(v.begin(), v.end()));
}

int main(int argc, const char * argv[])
{
    test();
    testForwardIterator();
    testReverseIterator();
    
    testRBT();
}
