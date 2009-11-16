#include "BinarySearchTree.h"

template<class K, class T>
BinarySearchTree<K, T>::TreeElement::TreeElement(const K &key, const T &value)
{
    left = right = parent = NULL;
    this->key = key;
    this->value = value;
}

template<class K, class T>
BinarySearchTree<K, T>::TreeElement::~TreeElement()
{
    if(left) delete left;
    if(right) delete right;
}

template<class K, class T>
BinarySearchTree<K, T>::BinarySearchTree()
{
    root = NULL;
}

template<class K, class T>
BinarySearchTree<K, T>::~BinarySearchTree()
{
    if(root) delete root;
}

template<class K, class T>
BinarySearchTree<K, T>::TreeElement **BinarySearchTree<K, T>::get(const K&)
{
    /* Current search position in the tree. */
    TreeElement **node = &root;

    /* Search the tree. */
    while(*node && key != (*node)->key) {
        if(key < (*node)->key) node = &((*node)->left);
        else node = &((*node)->right);
    }

    return node;
}

template<class K, class T>
void BinarySearchTree<K, T>::insert(const K &key, const T &value)
{
    /* Current search position in the tree. */
    TreeElement *node = root;

    /* Keep track of the parent. */
    TreeElement *parent = NULL;

    /* Flag to indicate we found the node. */
    bool found = false;

    while(node && !found) {
        parent = node;

        /* Smaller, take left child. */
        if(key < node->key) {
            node = node->left;
        /* Larger, take right child. */
        } else if (key > node->key) {
            node = node->right;
        } else {
            /* Cannot insert element. */
            return;
        }
    }

    if(parent) {
        node = new TreeElement(key, value);
        node->parent = parent;
        (key < node->key ? parent->left : parent->right) = node;
    } else {
        root = new TreeElement(key, value);
    }
}
