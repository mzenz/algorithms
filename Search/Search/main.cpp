#include <iostream>
#include "BinarySearchTree.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    BinarySearchTree<char, std::string> t;
	auto v = t.get('C');
	cout << "v = " << (v ? *v : "null")<< endl;
    auto min = t.min();
    auto max = t.max();
    cout << "min = " << (min ? *min : "null")<< endl;
    cout << "max = " << (max ? *max : "null")<< endl;

//	t.insert('X', "xx");
//	t.insert('S', "ss");
//	t.insert('B', "bb");
//	t.insert('C', "cc");
//	t.insert('A', "aa");
//	t.insert('C', "CCC");

	t.insert('D', "d");
	t.insert('A', "a");
    t.insert('R', "r");
	t.insert('B', "b");
    t.insert('C', "c");
    t.insert('X', "x");

	v = t.get('C');
    cout << "v = " << (v ? *v : "null")<< endl;
    min = t.min();
    max = t.max();
    cout << "min = " << (min ? *min : "null")<< endl;
    cout << "max = " << (max ? *max : "null")<< endl;
}
