#include "BinarySearchTree.h"
#include <exception>

using namespace std;

template<class K, class T>
BinarySearchTree<K, T>::BinarySearchTree()
{
    setRoot(NULL);
    size = 0;
}

template<class K, class T>
BinarySearchTree<K, T>::~BinarySearchTree()
{
    if(root) delete root;
}

template<class K, class T>
void BinarySearchTree<K, T>::insert(const K &key, const T &value)
{
    /* Find a good position. */
    TreeElement *parent;
    TreeElement *node = get(key, &parent);

    /* Key exists, override value. */
    if(node) {
        node->value = value;
    /* Add new element. */
    } else {
        node = new TreeElement(key, value);
        if(parent) {
            if(node->key < parent->key) parent->setLeft(node);
            else parent->setRight(node);
        } else {
            setRoot(node);
        }

        size++;
    }

    splay(node);
}

template<class K, class T>
bool BinarySearchTree<K, T>::contains(const K &key)
{
    TreeElement *parent;
    TreeElement *node = get(key, &parent);
    splay(node);
    return node != NULL;
}

template<class K, class T>
T *BinarySearchTree<K, T>::find(const K &key)
{
    TreeElement *parent;
    TreeElement *node = get(key, &parent);
    splay(node);
    if(node != NULL) {
        return &(node->value);
    } else {
        return NULL;
    }
}

template<class K, class T>
T *BinarySearchTree<K, T>::getAllValues(int &arraySize) const
{
    if(root == NULL) {
        arraySize = 0;
        return 0;
    } else {
        arraySize = size;
        T *array = new T[size];
        int position = 0;
        getAllValues(array, position, root);
        return array;
    }
}

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
void BinarySearchTree<K, T>::TreeElement::setLeft(
        typename BinarySearchTree<K, T>::TreeElement *left)
{
    this->left = left;
    if(left) left->parent = this;
}

template<class K, class T>
void BinarySearchTree<K, T>::TreeElement::setRight(
        typename BinarySearchTree<K, T>::TreeElement *right)
{
    this->right = right;
    if(right) right->parent = this;
}

template<class K, class T>
typename BinarySearchTree<K, T>::TreeElement *BinarySearchTree<K, T>::get(
        const K &key,
        typename BinarySearchTree::TreeElement **parent)
{
    /* Current search position in the tree. */
    *parent = NULL;
    TreeElement *node = root;
    while(node && !(key == node->key)) {
        *parent = node;
        if(key < node->key) node = node->left;
        else node = node->right;
    }

    return node;
}

template<class K, class T> typename
BinarySearchTree<K, T>::TreeElement *BinarySearchTree<K, T>::splayOnce(
        typename BinarySearchTree<K, T>::TreeElement *lower)
{
    /* Find two other nodes. */
    TreeElement *middle = lower->parent;
    if(!middle) return NULL;
    TreeElement *upper = middle->parent;
    if(!upper) return NULL;

    TreeElement *originalParent = upper->parent;
    TreeElement *newUpper;

    TreeElement *children[4];

    if(upper->left == middle) {
        /* lower (left) middle (left) upper */
        if(middle->left == lower) {
            children[2] = middle->right;
            children[3] = upper->right;

            middle->setLeft(lower);
            middle->setRight(upper);
            upper->setLeft(children[2]);
            upper->setRight(children[3]);

            newUpper = middle;
        /* lower (right) middle (left) upper */
        } else {
            children[1] = lower->left;
            children[2] = lower->right;

            lower->setLeft(middle);
            lower->setRight(upper);
            middle->setRight(children[1]);
            upper->setLeft(children[2]);

            newUpper = lower;
        }
    } else {
        /* lower (left) middle (right) upper */
        if(middle->left == lower) {
            children[1] = lower->left;
            children[2] = lower->right;

            lower->setLeft(upper);
            lower->setRight(middle);
            upper->setRight(children[1]);
            middle->setLeft(children[2]);

            newUpper = lower;
        /* lower (right) middle (right) upper */
        } else {
            children[1] = middle->left;

            middle->setLeft(upper);
            upper->setRight(children[1]);

            newUpper = middle;
        }
    }

    newUpper->parent = originalParent;
    if(!originalParent) {
        setRoot(newUpper);
    } else {
        if(newUpper->key < originalParent->key)
            originalParent->setLeft(newUpper);
        else
            originalParent->setRight(newUpper);
    }

    return newUpper;
}

template<class K, class T>
void BinarySearchTree<K, T>::splay(
        typename BinarySearchTree<K, T>::TreeElement *node)
{
    while(node) {
        node = splayOnce(node);
    }
}

template<class K, class T>
void BinarySearchTree<K, T>::setRoot(
        typename BinarySearchTree<K, T>::TreeElement *root)
{
    this->root = root;
    if(root) root->parent = NULL;
}

template<class K, class T>
void BinarySearchTree<K, T>::getAllValues(T *array, int &position,
        typename BinarySearchTree<K, T>::TreeElement *node) const
{
    if(node->left)
        getAllValues(array, position, node->left);

    array[position] = node->value;
    position++;

    if(node->right)
        getAllValues(array, position, node->right);
}
