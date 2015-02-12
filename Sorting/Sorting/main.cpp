#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Select.h"
#include <iostream>
#include <algorithm>

template<class T>
void p(const std::vector<T>& v)
{
	for(auto d : v) {
		std::cout << d;
	}
	std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
//	std::vector<double> v { 6.22, 1.23, 4.54, 0.91, 3.14, 0.03, -5.66, -2.01, 10.9, 7.24 };
	std::vector<char> v { 'S','O','R','T','E','X','A','M','P','L','E' };

	std::cout << "before:\n";
	p(v);


//	for (size_t k = 0; k < v.size(); ++k) {
//		auto v1(v);
//		std::cout << k << " element = " << (char)select(v1, k) << std::endl;
//		std::nth_element(v1.begin(), v1.begin() + k, v1.end());
//		std::cout << k << " element = " << v1[k] << std::endl;
//	}

//	selectionSort(v);
//	insertionSort(v);
//	shellSort(v);
//	mergeSort(v);
	quickSort(v);

//	std::sort(v.begin(), v.end());
//	std::stable_sort(v.begin(), v.end());

	std::cout << "\nafter:\n";
	p(v);
	std::cout << "\nsorted? " << (std::is_sorted(v.begin(), v.end()) ? "YES" : "NOPE") << std::endl;

	return 0;
}
