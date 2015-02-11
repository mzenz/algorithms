#pragma once

#include "Shuffle.h"
#include <vector>

template<class T>
int partition(std::vector<T>& v, int lo, int hi)
{
	int i = lo, j = hi+1;
	while (true) {
		while (v[++i] < v[lo])
			if (i == hi)
				break;

		while (v[lo] < v[--j])
			if (j == lo)
				break;

		if (i >= j)
			break;
		std::swap(v[i], v[j]);
	}

	std::swap(lo, j);
	return j;
}

template<class T>
void sort(std::vector<T>& v, int lo, int hi)
{
	if (hi > lo) {
		int j = partition(v, lo, hi);
		sort(v, lo, j-1);
		sort(v, j+1, hi);
	}
}

// O(N) = N lg N
template<class T>
void quickSort(std::vector<T>& v)
{
	shuffle(v);
	sort(v, 0, (int)v.size() - 1);
}
