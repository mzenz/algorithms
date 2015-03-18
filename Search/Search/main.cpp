#include <iostream>
#include "BinarySearchTree.h"
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char * argv[])
{
	typedef BinarySearchTree<char, std::string> BST;
    BST t;
	auto v = t.get('C');
	cout << "v = " << (v ? *v : "null")<< endl;
    auto min = t.min();
    auto max = t.max();
    cout << "min = " << (min ? *min : "null")<< endl;
    cout << "max = " << (max ? *max : "null")<< endl;

	t.insert('D', "d");
	t.insert('A', "a");
	t.insert('B', "b");
    t.insert('C', "c");
    t.insert('X', "x");
    t.insert('R', "r");

	v = t.get('C');
    cout << "v = " << (v ? *v : "null")<< endl;
    min = t.min();
    max = t.max();
    cout << "min = " << (min ? *min : "null")<< endl;
    cout << "max = " << (max ? *max : "null")<< endl;

	cout << "forward order: ";
    for (auto it = t.begin(); it.valid(); ++it)
        cout << *it.get() << ", ";
    cout << endl;

	cout << "reverse order: ";
    for (auto it = t.rbegin(); it.valid(); ++it)
        cout << *it.get() << ", ";
    cout << endl;
}
