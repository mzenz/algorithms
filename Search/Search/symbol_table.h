#pragma once

#include <vector>

template<typename K, typename T>
class symbol_table
{
public:
    void insert(K key, const T& value);
    T& get(K key);
    const T& get(K key) const;

    void remove(K key);

    bool exists(K key) const;
    
    bool empty() const;
    size_t size() const;

    void getKeys() const;

private:
};
