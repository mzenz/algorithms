#pragma once

#include <vector>
#include <cassert>

template<typename T>
class binary_heap
{
public:
	binary_heap(size_t capacity = 0)
	{
		if (capacity)
			_v.reserve(capacity);
	}

	size_t size() const { return _v.size(); }
	size_t empty() const { return _v.empty(); }

	void print()
	{
		for (auto i = 0; i < _v.size(); ++i)
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

		T t(_v[0]);
		_v[0] = _v.back();
		_v.pop_back();
		sink(0, _v.size());
		return t;
	}

private:
	void swim(size_t i)
	{
        for (size_t p = (i - 1) / 2; i > 0 && _v[i] > _v[p]; i = p, p = (i - 1) / 2)
            std::swap(_v[i], _v[p]);
	}

	void sink(size_t i, size_t size)
	{
        size_t j = 2 * i + 1;
        while (j < size) {
            // pick i's greatest child (if there are more than one)
            if (j+1 < size && _v[j+1] > _v[j]) ++j;
            if (_v[i] >= _v[j]) break;
            std::swap(_v[i], _v[j]);
            i = j;
            j = 2 * i + 1;
        }
	}

    // _v is zero-based, meaning that the root of the heap sits at _v[0]
	std::vector<T> _v;
};
