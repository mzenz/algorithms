#include <iostream>
#include "UnionFind.h"

using namespace std;

void isConnected(UnionFind& uf, int p, int q)
{
	cout << "connected(" << p << "," << q << ") : " << (uf.connected(p,q) ? "yes" : "no") << endl;
}

int main(int argc, const char * argv[])
{
//	QuickFind uf(10);
//	QuickUnion uf(10);
	WeightedQuickUnion uf(10);

//	cout << "before: " << uf << endl;

	uf.merge(4,3);
	uf.merge(3,8);
	uf.merge(6,5);
	uf.merge(9,4);
	uf.merge(2,1);
	uf.merge(5,0);
	uf.merge(7,2);
	uf.merge(6,1);
	uf.merge(7,3);

//	isConnected(uf, 8,9);
//	isConnected(uf, 5,4);
//	isConnected(uf, 5,0);
	
	cout << "after:\n" << uf << endl;

	cout << endl;
}
