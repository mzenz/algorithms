#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
bool isSorted(const std::vector<T>& v) {
	for (size_t i = 0; i < v.size() - 1; ++i) {
		if (v[i] > v[i+1])
			return false;
	}
	return true;
}

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

template<class T>
void selectionSort(std::vector<T>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		size_t min = i;
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min]) // compare
				min = j;
		}
		std::swap(v[i], v[min]); // exchange
	}
};

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

template<class T>
void mergeSort(std::vector<T>& v)
{
	std::vector<T> aux(v.size());
	for (size_t i = 0; i < v.size(); ++i) {
	}
};

int main(int argc, const char * argv[]) {
//	std::vector<double> v { 6.22, 1.23, 4.54, 0.91, 3.14, 0.03, -5.66, -2.01, 10.9, 7.24 };
	std::vector<char> v { 'S','O','R','T','E','X','A','M','P','L','E' };

	std::cout << "before:\n";
	for(auto d : v) {
		std::cout << d << " ";
	}
	std::cout << std::endl;

//	selectionSort(v);
//	insertionSort(v);
	shellSort(v);

	std::cout << "\nafter:\n";
	for(auto d : v) {
		std::cout << d << " ";
	}
	std::cout << std::endl;
	std::cout << "\nsorted? " << (isSorted(v) ? "YES" : "NOPE") << std::endl;

	shuffle(v);
	std::cout << "\nafter:\n";
	for(auto d : v) {
		std::cout << d << " ";
	}
	std::cout << std::endl;

	return 0;
}
