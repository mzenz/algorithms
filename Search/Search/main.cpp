#include <iostream>
#include "BinarySearchTree.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[])
{
    BinarySearchTree<char, std::string> t;
	auto v = t.get('C');
	cout << "v = " << (v ? *v : "null")<< endl;
	
//	t.insert('X', "xx");
//	t.insert('S', "ss");
//	t.insert('B', "bb");
//	t.insert('C', "cc");
//	t.insert('A', "aa");
//	t.insert('C', "CCC");

	t.insert('D');
	t.insert('A');
	t.insert('B');
	t.insert('C');

	v = t.get('C');
	cout << "v = " << (v ? *v : "null")<< endl;
}
