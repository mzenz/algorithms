#pragma once

#include "InsertionSort.h"

// O(N) = N^(3/2)
template<class T>
void shellSort(std::vector<T>& v)
{
	int h = 1;
	while (h < v.size() / 3)
		h = 3 * h + 1;

	for (; h > 0; h /= 3)
		hSort(v, h);
};
