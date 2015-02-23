#include <iostream>
#include <vector>

template<typename T>
class binary_heap
{
public:
	binary_heap(size_t capacity = 0)
	{
		if (capacity)
			_v.reserve(capacity);
		_v.push_back('\0');
	}

	binary_heap(std::initializer_list<T> l)
		: _v(l.size() + 1)
	{
		auto it = _v.begin();
		*it = '\0';
		++it;
		for (auto ll = l.begin(); it != _v.end(); ++ll, ++it)
			*it = *ll;
	}

	size_t size() const { return _v.size() - 1; }
	size_t empty() const { return size() == 0; }

	void print()
	{
		for (auto i = 1; i < _v.size(); ++i)
			std::cout << _v[i] << " ";
		std::cout << std::endl;
	}

	void insert(const T& value)
	{
		_v.push_back(value);
		swim(_v.size() - 1);
	}

	T remove()
	{
		if (empty())
			return;

		T t(_v[1]);
		_v[1] = _v.back();
		_v.pop_back();
		sink(1);
		return t;
	}

	void heap_sort() {
		// first pass: sink everything starting from lowest parent
		// all the way to the root (this is fucking genius)
		// NOTE: O(N) = 2N  ---> PRETTY SWEET!
		for (size_t i = size() / 2; i > 0; --i)
			sink(i, _v.size());

		// second pass:
		// - Swap greatest element (i.e. the root) with last the element
		// - Leave greatest element (just swapped to the bottom of the heap) and sink
		//   new root as if the heap just shrunk by 1 (this way all biggest elements
		//   stay ordered at the end)
		for (size_t i = size(); i > 1; --i) {
			std::swap(_v[1], _v[i]);
			sink(1, i);
		}
	}

private:
	void swim(size_t i)
	{
		for (size_t p = i / 2; i > 1 && _v[i] > _v[p]; i = p, p = i / 2)
			std::swap(_v[i], _v[p]);
	}

	void sink(size_t i, size_t size)
	{
		while (2 * i < size) {
			size_t j = 2 * i;
			// pick i's greatest child (if there are more than one)
			if (j+1 < size && _v[j+1] > _v[j]) ++j;
			if (_v[i] >= _v[j]) break;
			std::swap(_v[i], _v[j]);
			i = j;
		}
	}

	std::vector<T> _v;
};

int main(int argc, const char * argv[])
{
//	binary_heap<char> h { 'X','V','U','S','Q','H','G','J','M','P' };
	binary_heap<char> h { 'S','O','R','T','E','X','A','M','P','L','E' };

	std::cout << "Heap before:" << std::endl;
	h.print();
	std::cout << std::endl;

	h.heap_sort();
	std::cout << "Heap after heapsort:" << std::endl;
	h.print();
//	std::cout << "sorted? " << (std::is_sorted(++h._v.begin(), h._v.end()) ? "YES" : "NO") << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
}
