#pragma once

#include <vector>
#include <cassert>

// binary heap simple implementation (i.e. v is one-based since the heap's root is at i = 1)
template<typename T>
class binary_heap_simple
{
public:
	binary_heap_simple(size_t capacity = 0)
	{
		if (capacity)
			_v.reserve(capacity);
		_v.push_back('\0');
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
        assert(!empty());

		T t(_v[1]);
		_v[1] = _v.back();
		_v.pop_back();
		sink(1, _v.size());
		return t;
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
