#pragma once

#include <stack>
#include <cassert>

//#define RECURSIVE_INSERT

template<typename K, typename T>
class BinarySearchTree
{
public:
//    class Iterator;

	BinarySearchTree();

    T* get(K key);
	const T* get(K key) const;

	bool exists(K key) const;

    void insert(K key, const T& value = T());

    void remove(K key);

	bool empty() const { return _root; }
	size_t size() const { return _size; }

    T* min() const;
    T* max() const;

    void removeMin();
    void removeMax();
    
    K select(size_t rank) const;
    
    size_t rank(K key) const;
    
    T floor(K key) const;

    T ceiling() const;

    size_t count(K lo, K hi) const;
    
    void keys() const;
    
    class Iterator;

    Iterator begin();

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
	
#ifdef RECURSIVE_INSERT
	Node* insert(Node* node, K key, const T& value);
#endif

	Node* findNode(K key);
	
    Node* _root;
	size_t _size;
};

template<typename K, typename T>
class BinarySearchTree<K,T>::Iterator
{
public:
    bool valid() const { return !s.empty(); }
    void operator++() {
        s.pop();
        if (s.top()->_right) {
            Node* right = s.top()->_right;
            s.push(right);
            pushAllLeft(right);
        }
    }
    
    T* get() {
        if (s.empty())
            return nullptr;
        return &s.top()->_value;
    }
private:
    friend class BinarySearchTree<K,T>;
    
    Iterator(Node* n) {
        assert(n);
        pushAllLeft(n);
    }

    void pushAllLeft(Node* n) {
        assert(n);
        while (n->_left) {
            s.push(n->_left);
            n = n->_left;
        }
    }

    std::stack<Node*> s;
};

template<typename K, typename T>
typename BinarySearchTree<K,T>::Iterator BinarySearchTree<K,T>::begin()
{
    return Iterator(_root);
}

template<typename K, typename T>
BinarySearchTree<K,T>::BinarySearchTree()
	: _root(nullptr)
	, _size(0)
{
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

#ifdef RECURSIVE_INSERT
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

#else
template<typename K, typename T>
void BinarySearchTree<K,T>::insert(K key, const T& value)
{
	Node** node = &_root;
	while (*node) {
		if      (key < (*node)->_key) node = &(*node)->_left;
		else if (key > (*node)->_key) node = &(*node)->_right;
		else {
			// if value matches node replace value and return, nothing else to do
			(*node)->_value = value;
			return;
		}
	}
	++_size;
	*node = new Node(key, value);
}
#endif

template<typename K, typename T>
void BinarySearchTree<K,T>::remove(K key)
{
	auto node = findNode(key);
	if (node) {
		
	}
}

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





