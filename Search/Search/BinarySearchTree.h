#pragma once

#include <stack>
#include <vector>
#include <cassert>

//#define RECURSIVE_INSERT

template<typename K, typename T>
class BinarySearchTree
{
public:
    typedef K KeyType;
    typedef T ValueType;

    BinarySearchTree();
	BinarySearchTree(std::initializer_list<std::pair<K,T>> list);
	BinarySearchTree(std::initializer_list<K> list);

    T* get(K key);
	const T* get(K key) const;

	bool exists(K key) const;

    bool insert(K key, const T& value = T());

    // unimplemented
    void remove(K key);

	bool empty() const { return _root; }
	size_t size() const { return _size; }

    T* min() const;
    T* max() const;

    // unimplemented
    void removeMin();
    // unimplemented
    void removeMax();
    // unimplemented
    K select(size_t rank) const;
    // unimplemented
    size_t rank(K key) const;
    // unimplemented
    T floor(K key) const;
    // unimplemented
    T ceiling() const;
    // unimplemented
    size_t count(K lo, K hi) const;
    // unimplemented
    void keys() const;
    
    class Iterator;
    class ReverseIterator;

    Iterator begin();
    ReverseIterator rbegin();

private:
    struct Node {
		Node(K key, const T& value)
			: _key(key)
			, _value(value)
			, _left(nullptr)
			, _right(nullptr)
		{
		}

        K _key;
        T _value;
		Node* _left;
		Node* _right;
    };

    class IteratorBase;

#ifdef RECURSIVE_INSERT
	Node* insert(Node* node, K key, const T& value);
#endif

	Node* findNode(K key);
	
    Node* _root;
	size_t _size;
};

template<typename K, typename T>
BinarySearchTree<K,T>::BinarySearchTree()
	: _root(nullptr)
	, _size(0)
{
}

template<typename K, typename T>
BinarySearchTree<K,T>::BinarySearchTree(std::initializer_list<std::pair<K,T>> list)
    : BinarySearchTree()
{
	for(const auto& p : list)
		insert(p.first, p.second);
}

template<typename K, typename T>
BinarySearchTree<K,T>::BinarySearchTree(std::initializer_list<K> list)
    : BinarySearchTree()
{
	for(const auto& k : list)
		insert(k);
}

template<typename K, typename T>
typename BinarySearchTree<K,T>::Node* BinarySearchTree<K,T>::findNode(K key)
{
	Node** node = &_root;
	while (*node) {
		if      (key < (*node)->_key) node = &(*node)->_left;
		else if (key > (*node)->_key) node = &(*node)->_right;
		else                          return   *node;
	}
	return nullptr;
}

template<typename K, typename T>
T* BinarySearchTree<K,T>::get(K key)
{
	auto node = findNode(key);
	return node ? &node->_value : nullptr;
}

template<typename K, typename T>
bool BinarySearchTree<K,T>::exists(K key) const
{
	return findNode(key);
}

#ifndef RECURSIVE_INSERT
template<typename K, typename T>
bool BinarySearchTree<K,T>::insert(K key, const T& value)
{
    Node** node = &_root;
    while (*node) {
        if      (key < (*node)->_key) node = &(*node)->_left;
        else if (key > (*node)->_key) node = &(*node)->_right;
        else {
            // if value matches node replace value and return, nothing else to do
            (*node)->_value = value;
            return false;
        }
    }
    ++_size;
    *node = new Node(key, value);
    return true;
}
#else
template<typename K, typename T>
typename BinarySearchTree<K,T>::Node* BinarySearchTree<K,T>::insert(Node* node, K key, const T& value)
{
    if (node == nullptr) {
        ++_size;
        return new Node(key, value);
    }
    if      (key < node->_key) node->_left  = insert(node->_left, key, value);
    else if (key > node->_key) node->_right = insert(node->_right, key, value);
    else                       node->_value = value;
    return node;
}

template<typename K, typename T>
void BinarySearchTree<K,T>::insert(K key, const T& value)
{
    _root = insert(_root, key, value);
}
#endif

template<typename K, typename T>
T* BinarySearchTree<K,T>::min() const
{
    Node* n = _root;
    while (n) {
        if (!n->_left)
            return &n->_value;
        n = n->_left;
    }
    return nullptr;
}

template<typename K, typename T>
T* BinarySearchTree<K,T>::max() const
{
    Node* n = _root;
    while (n) {
        if (!n->_right)
            return &n->_value;
        n = n->_right;
    }
    return nullptr;
}

template<typename K, typename T>
typename BinarySearchTree<K,T>::Iterator BinarySearchTree<K,T>::begin()
{
    return Iterator(_root);
}

template<typename K, typename T>
typename BinarySearchTree<K,T>::ReverseIterator BinarySearchTree<K,T>::rbegin()
{
    return ReverseIterator(_root);
}

////////////////////////////////
// Iterator implementations
////////////////////////////////
template<typename K, typename T>
class BinarySearchTree<K,T>::IteratorBase
{
public:
    bool valid() const { return !s.empty(); }
    
    T* value() { return s.empty() ? nullptr : &s.top()->_value; }
    T* key() { return s.empty() ? nullptr : &s.top()->_key; }
    T& operator*() { assert(valid()); return s.top()->_value; }
    T& operator->() { return **this; }
    
protected:
    void pushAllLeft(Node* n)
    {
        for (; n; n = n->_left)
            s.push(n);
    }
    
    void pushAllRight(Node* n)
    {
        for (; n; n = n->_right)
            s.push(n);
    }
    
    std::stack<Node*> s;
};

template<typename K, typename T>
class BinarySearchTree<K,T>::Iterator : public BinarySearchTree<K,T>::IteratorBase
{
public:
    void operator++()
    {
        if (IteratorBase::s.empty())
            return;
        
        auto right = IteratorBase::s.top()->_right;
        IteratorBase::s.pop();
        if (right)
            IteratorBase::pushAllLeft(right);
    }
    
private:
    friend class BinarySearchTree<K,T>;
    
    Iterator(Node* n) { IteratorBase::pushAllLeft(n); }
};

template<typename K, typename T>
class BinarySearchTree<K,T>::ReverseIterator : public BinarySearchTree<K,T>::IteratorBase
{
public:
    void operator++()
    {
        if (IteratorBase::s.empty())
            return;
        
        auto left = IteratorBase::s.top()->_left;
        IteratorBase::s.pop();
        if (left)
            IteratorBase::pushAllRight(left);
    }
    
private:
    friend class BinarySearchTree<K,T>;
    
    ReverseIterator(Node* n) { IteratorBase::pushAllRight(n); }
};
