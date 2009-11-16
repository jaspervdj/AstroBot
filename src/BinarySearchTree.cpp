#include "BinarySearchTree.h"
#include <exception>

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

template<class K, class T> typename 
BinarySearchTree<K, T>::TreeElement **BinarySearchTree<K, T>::find(const K &key)
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
void BinarySearchTree<K, T>::put(const K &key, const T &value)
{
    /* Find a good position. */
    TreeElement **node = find(key);
    if(*node) (*node)->value = value;
    else *node = new TreeElement(key, value);
}

template<class K, class T>
bool BinarySearchTree<K, T>::contains(const K &key)
{
    TreeElement **node = find(key);
    return *node != NULL;
}

template<class K, class T>
const T &BinarySearchTree<K, T>::get(const K &key)
{
    class ElementNotFoundException: public std::exception
    {
        virtual const char* what() const throw()
        {
            return "No such element.";
        }
    };

    TreeElement **node = find(key);
    if(*node != NULL) return (*node)->value;
    else throw ElementNotFoundException();
}
