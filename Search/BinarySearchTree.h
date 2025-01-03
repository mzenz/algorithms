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
  void erase(K key);

  bool empty() const { return _root; }
  size_t size() const { return _size; }

  const T* min() const;
  const T* max() const;

  // unimplemented
  void eraseMin();
  // unimplemented
  void eraseMax();
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
  const Iterator begin() const;
  const ReverseIterator rbegin() const;

private:
  enum class Color : bool { Red, Black };

  struct Node {
    K _key;
    T _value;
    Node* left;
    Node* right;
    Color color;

    Node(K key, const T& value, Color _color = Color::Black)
    : _key(key)
    , _value(value)
    , left(nullptr)
    , right(nullptr)
    , color(_color)
    {
    }
  };

  class IteratorBase;

#ifdef RECURSIVE_INSERT
  Node* insert(Node* node, K key, const T& value);
#endif

  struct NodePair
  {
    NodePair(Node* _node, Node* _parent) : node(_node), parent(_parent) {}

    Node* node;
    Node* parent;
  };

  NodePair findNode(K keykey, Node* root = nullptr);

  NodePair minNode(Node* node) {
    NodePair p(node, nullptr);
    while (p.node) {
      if (!p.node->left)
        return p;
      p.parent = p.node;
      p.node = p.node->left;
    }
    return NodePair(nullptr,nullptr);
  }

  NodePair maxNode(Node* node) {
    NodePair p(node, nullptr);
    while (p.node) {
      if (!p.node->right)
        return p;
      p.parent = p.node;
      p.node = p.node->right;
    }
    return NodePair(nullptr,nullptr);
  }

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
typename BinarySearchTree<K,T>::NodePair BinarySearchTree<K,T>::findNode(K key, Node* root)
{
  NodePair p(root ? root : _root, nullptr);
  for (auto i = 0; p.node; ++i) {
    if (key < p.node->_key) {
      p.parent = p.node;
      p.node = p.node->left;
    }
    else if (key > p.node->_key) {
      p.parent = p.node;
      p.node = p.node->right;
    }
    else
      return p;
  }
  return NodePair(nullptr,nullptr);
}

template<typename K, typename T>
T* BinarySearchTree<K,T>::get(K key)
{
  auto node = findNode(key);
  return node.node ? &node.node->_value : nullptr;
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
    if    (key < (*node)->_key) node = &(*node)->left;
    else if (key > (*node)->_key) node = &(*node)->right;
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
  if    (key < node->_key) node->left  = insert(node->left, key, value);
  else if (key > node->_key) node->right = insert(node->right, key, value);
  else             node->_value = value;
  return node;
}

template<typename K, typename T>
void BinarySearchTree<K,T>::insert(K key, const T& value)
{
  _root = insert(_root, key, value);
}
#endif

template<typename K, typename T>
void BinarySearchTree<K,T>::erase(K key)
{
  auto node = findNode(key);
  if (!node.node)
    return;

  // find successor as replacement
  auto replacement = minNode(node.node->right);
  if (replacement.node) {
    assert(replacement.parent->left == replacement.node);
    assert(replacement.node->left == nullptr);

    replacement.parent->left = replacement.node->right;
    if (node.parent->left == node.node)
      node.parent->left = replacement.node;
    else
      node.parent->right = replacement.node;

    replacement.node->left = node.node->left;
    replacement.node->right = node.node->right;
  }
  else {
    // find predecessor as replacement
    replacement = maxNode(node.node->left);
    if (replacement.node) {
      assert(replacement.parent->right == replacement.node);
      assert(replacement.node->right == nullptr);

      replacement.parent->right = replacement.node->left;
      if (node.parent->left == node.node)
        node.parent->left = replacement.node;
      else
        node.parent->right = replacement.node;

      replacement.node->left = node.node->left;
      replacement.node->right = node.node->right;
    }
    else {
      // there's no successor or predecessor
      if (node.parent->left == node.node)
        node.parent->left = nullptr;
      else
        node.parent->right = nullptr;
    }
  }

  delete node.node;
  --_size;
}

template<typename K, typename T>
const T* BinarySearchTree<K,T>::min() const
{
  Node* n = _root;
  while (n) {
    if (!n->left)
      return &n->_value;
    n = n->left;
  }
  return nullptr;
}

template<typename K, typename T>
const T* BinarySearchTree<K,T>::max() const
{
  Node* n = _root;
  while (n) {
    if (!n->right)
      return &n->_value;
    n = n->right;
  }
  return nullptr;
}

template<typename K, typename T>
typename BinarySearchTree<K,T>::Iterator BinarySearchTree<K,T>::begin()
{
  return Iterator(_root);
}

template<typename K, typename T>
const typename BinarySearchTree<K,T>::Iterator BinarySearchTree<K,T>::begin() const
{
  return Iterator(_root);
}

template<typename K, typename T>
typename BinarySearchTree<K,T>::ReverseIterator BinarySearchTree<K,T>::rbegin()
{
  return ReverseIterator(_root);
}

template<typename K, typename T>
const typename BinarySearchTree<K,T>::ReverseIterator BinarySearchTree<K,T>::rbegin() const
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
    for (; n; n = n->left)
      s.push(n);
  }

  void pushAllRight(Node* n)
  {
    for (; n; n = n->right)
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

    auto right = IteratorBase::s.top()->right;
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

    auto left = IteratorBase::s.top()->left;
    IteratorBase::s.pop();
    if (left)
      IteratorBase::pushAllRight(left);
  }

private:
  friend class BinarySearchTree<K,T>;

  ReverseIterator(Node* n) { IteratorBase::pushAllRight(n); }
};
