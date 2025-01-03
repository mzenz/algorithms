#pragma once

#include "BinarySearchTree.h"

template<typename K, typename T>
class RedBlackTree : public BinarySearchTree<K, T>
{
public:
  RedBlackTree();
  RedBlackTree(std::initializer_list<std::pair<K,T>> list);
  RedBlackTree(std::initializer_list<K> list);

  // TODO: define
//  bool insert(K key, const T& value = T());

private:
};

template<typename K, typename T>
RedBlackTree<K,T>::RedBlackTree()
{

}

template<typename K, typename T>
RedBlackTree<K,T>::RedBlackTree(std::initializer_list<std::pair<K,T>> list)
  : BinarySearchTree<K,T>(list)
{

}

template<typename K, typename T>
RedBlackTree<K,T>::RedBlackTree(std::initializer_list<K> list)
  : BinarySearchTree<K,T>(list)
{

}
