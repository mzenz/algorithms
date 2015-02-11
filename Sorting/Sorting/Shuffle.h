#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>

// O(N) = N
template<class T>
void shuffle(std::vector<T>& v)
{
	srand((unsigned)time(nullptr));
	for (size_t i = 0; i < v.size(); ++i) {
		int k = rand() * (i + 1) / RAND_MAX;
		std::swap(v[i], v[k]);
	}
};
