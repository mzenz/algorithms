#pragma once

#include <vector>

template<typename K, typename T>
class Dictionary
{
public:
    // getter
    T& get(K key);
    const T& get(K key) const;
    // setter
    void insert(K key, const T& value);

    void remove(K key);

    bool exists(K key) const;
    
    bool empty() const;
    size_t size() const;

    T min() const;
    T max() const;

    void removeMin();
    void removeMax();
    
    // Returns the key with the Nth highest rank
    K select(size_t rank) const;
    
    // Returns the number of keys with lower rank than the passed key
    size_t rank(K key) const;
    
    // Returns the value corresponding to the first key lower in rank than the passed key
    T floor(K key) const;

    // Returns the value corresponding to the first key higher in rank than the passed key
    T ceiling() const;

    size_t count(K lo, K hi) const;
    
    void keys() const;

private:
};
