#pragma once

#include <vector>

// base class
class UnionFind
{
public:
	UnionFind(size_t n);

	virtual void initialize();
	virtual void merge(int p, int q) = 0;
	virtual bool connected(int p, int q) = 0;

protected:
	friend std::ostream& operator<<(std::ostream& out, const UnionFind& uf);
	std::vector<int> _id;
};

struct QuickFind : public UnionFind
{
	QuickFind(int n) : UnionFind(n) {}

	virtual void merge(int p, int q);
	virtual bool connected(int p, int q);
};

struct QuickUnion : public UnionFind
{
	QuickUnion(size_t n) : UnionFind(n) {}

	virtual void merge(int p, int q);
	virtual bool connected(int p, int q);

protected:
	int root(int i);
};

struct WeightedQuickUnion : public QuickUnion
{
	WeightedQuickUnion(size_t n) : QuickUnion(n), _count(n, 1) {}

	virtual void merge(int p, int q);

private:
	std::vector<int> _count;
};
