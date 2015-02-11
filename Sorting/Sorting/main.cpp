#include <iostream>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

template<class T>
bool isSorted(const std::vector<T>& v) {
	for (size_t i = 0; i < v.size() - 1; ++i) {
		if (v[i] > v[i+1])
			return false;
	}
	return true;
}

int main(int argc, const char * argv[]) {
//	std::vector<double> v { 6.22, 1.23, 4.54, 0.91, 3.14, 0.03, -5.66, -2.01, 10.9, 7.24 };
	std::vector<char> v { 'S','O','R','T','E','X','A','M','P','L','E' };

	std::cout << "before:\n";
	for(auto d : v) {
		std::cout << d;
	}
	std::cout << std::endl;

//	selectionSort(v);
//	insertionSort(v);
//	shellSort(v);
//	mergeSort(v);
	quickSort(v);

	std::cout << "\nafter:\n";
	for(auto d : v) {
		std::cout << d;
	}
	std::cout << std::endl;
	std::cout << "\nsorted? " << (isSorted(v) ? "YES" : "NOPE") << std::endl;

//	shuffle(v);
//	std::cout << "\nshuffled:\n";
//	for(auto d : v) {
//		std::cout << d;
//	}
//	std::cout << std::endl;

	return 0;
}
