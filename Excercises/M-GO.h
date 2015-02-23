#pragma once

#include <vector>
#include <unordered_map>
#include <cstdio> // printf()

// M-GO excercise: find the two values in v[] (v[i],v[j]) that fulfill
void sumT(const std::vector<int>& v, int t) {
	std::unordered_map<int,size_t> h;

	for (size_t i = 0; i < v.size(); ++i)
		h[v[i]] = i;

	for (size_t i = 0; i < v.size(); ++i) {
		auto it = h.find(t - v[i]);
		if (it != h.end() && it->second != i) {
			printf("%d + %d = %d (i = %ld, j = %ld)\n", v[i], it->first, t, i, it->second);
		}
	}
}
