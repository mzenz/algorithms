#pragma once

#include <vector>

template<class T>
void hSort(std::vector<T>& v, size_t h = 1)
{
	for (size_t i = h; i < v.size(); ++i) {
		for (size_t j = i; j >= h && v[j] < v[j - h]; j -= h)
			std::swap(v[j], v[j - h]);
	}
};

template<class T>
void insertionSort(std::vector<T>& v)
{
	hSort(v, 1);
};
