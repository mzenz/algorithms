#include <iostream>
#include <vector>

template<class T>
void selectionSort(std::vector<T>& v)
{
	for(size_t i = 0; i < v.size(); ++i) {
		size_t min = i;
		for(size_t j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[min]) // compare
				min = j;
		}
		std::swap(v[i], v[min]); // exchange
	}
};

template<class T>
void insertionSort(std::vector<T>& v)
{
	for(int i = 0; i < v.size(); ++i) {
		for(int j = i; j > 0; --j) {
			if(v[j] > v[j-1])
				break;
			std::swap(v[j], v[j-1]);
		}
	}
};

int main(int argc, const char * argv[]) {
	std::vector<double> v { 6.22, 1.23, 4.54, 0.91, 3.14 };

	std::cout << "before:\n";
	for(auto d : v) {
		std::cout << d << ", ";
	}
	std::cout << std::endl;
	
//	selectionSort(v);
	insertionSort(v);
	
	std::cout << "after:\n";
	for(auto d : v) {
		std::cout << d << ", ";
	}
	std::cout << std::endl;
	return 0;
}
