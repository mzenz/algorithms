#include "UnionFind.h"
#include <ostream>
#include <cassert>

std::ostream& operator<<(std::ostream& out, const UnionFind& uf)
{
	out << "|";
	for (auto i = 0; i < uf._id.size(); ++i)
		out << i  << "|";
	out << "\n ";
	for (auto i : uf._id)
		out << i  << " ";
	return out;
}

////////////////////////////////////////////////////////////////

UnionFind::UnionFind(size_t n)
	: _id(n)
{
	initialize();
}

void UnionFind::initialize()
{
	for (size_t i = 0; i < _id.size(); ++i)
		_id[i] = (int)i;
}

////////////////////////////////////////////////////////////////
bool QuickFind::connected(int p, int q)
{
	return _id[q] == _id[p];
}

void QuickFind::merge(int p, int q)
{
	if (connected(p, q))
		return; // nothing to merge

	const auto newId = _id[q];
	const auto oldId = _id[p];
	for (int i = 0; i < _id.size(); ++i) {
		if (_id[i] == oldId)
			_id[i] = newId;
	}
	_id[q] = _id[p];
}

////////////////////////////////////////////////////////////////

int QuickUnion::root(int i)
{
	while(i != _id[i]) {
		_id[i] = _id[_id[i]];
		i = _id[i];
	}
	return i;
}

bool QuickUnion::connected(int p, int q)
{
	return root(p) == root(q);
}

void QuickUnion::merge(int p, int q)
{
	_id[root(p)] = root(q);
}

////////////////////////////////////////////////////////////////

void WeightedQuickUnion::merge(int p, int q)
{
	auto rp = root(p);
	auto rq = root(q);
	if (rp == rq) return;

	if (_count[rp] < _count[rq]) {
		_id[rp] = rq; _count[rq] += _count[rp];
	}
	else {
		_id[rq] = rp; _count[rp] += _count[rq];
	}
}
