/* Practicum 5, Jasper Van der Jeugt
 * BinarySearchTree.cpp
 */
#include "BinarySearchTree.h"
using std::string;

TreeElement::TreeElement()
{
    left = right = parent = NULL;
}

TreeElement::TreeElement(const string &key)
{
    left = right = parent = NULL;
    this->key = key;
}

TreeElement::~TreeElement()
{
    if(left) delete left;
    if(right) delete right;
}

BinarySearchTree::BinarySearchTree()
{
    root = NULL;
    size = 0;
}

bool BinarySearchTree::isEmpty()
{
    return root == NULL;
}

bool BinarySearchTree::insert(const string &key)
{
    /* Current search position in the tree. */
    TreeElement *node = root;

    /* Keep track of the parent. */
    TreeElement *parent = NULL;

    /* Flag to indicate we found the node. */
    bool found = false;

    /* Compare result. */
    int compare;

    while(node && !found) {
        parent = node;
        compare = key.compare(node->key);

        /* Smaller, take left child. */
        if(compare < 0) {
            node = node->left;
        /* Larger, take right child. */
        } else if (compare > 0) {
            node = node->right;
        /* Equal, found. */
        } else {
            return false;
        }
    }

    if(parent) {
        node = new TreeElement(key);
        node->parent = parent;
        (compare < 0 ? parent->left : parent->right) = node;
    } else {
        root = new TreeElement(key);
    }

    size++;

    return true;
}

bool BinarySearchTree::contains(const string &key)
{
    return get(key) != NULL;
}

string *BinarySearchTree::getValuesInRange(const std::string &start,
        const std::string &stop, int* arraySize)
{
    /* Check inclusion of both delimiters. */
    if(!root || !contains(start) || !contains(stop)) {
        *arraySize = 0;
        return 0;
    }

    *arraySize = 4;
    int position = 0;
    string *array = new string[*arraySize];
    addToArray(root, &array, arraySize, &position, start, stop);
    *arraySize = position;

    return array;
}

string *BinarySearchTree::getAllValues(int* arraySize)
{
    if(!root) {
        *arraySize = 0;
        return 0;
    }

    *arraySize = size;
    string *array = new string[size];
    int position = 0;
    addToArray(root, array, &position);

    return array;
}

BinarySearchTree::~BinarySearchTree()
{
    if(root) delete root;
}

TreeElement *BinarySearchTree::get(const string &key)
{
    /* Current search position in the tree. */
    TreeElement *node = root;

    /* Flag to indicate we found the node. */
    bool found = false;

    while(node && !found) {
        int compare = key.compare(node->key);

        /* Smaller, take left child. */
        if(compare < 0) {
            node = node->left;
        /* Larger, take right child. */
        } else if (compare > 0) {
            node = node->right;
        /* Equal, found. */
        } else {
            found = true;
        }
    }

    return node;
}

void BinarySearchTree::addToArray(TreeElement *element, string *array,
        int *position) const
{
    if(element->left)
        addToArray(element->left, array, position);

    array[*position] = element->key;
    (*position)++;

    if(element->right)
        addToArray(element->right, array, position);
}

void BinarySearchTree::addToArray(TreeElement *element, std::string **array,
        int *arraySize, int *position, const std::string &start,
        const std::string &stop) const
{
    if(element->left && element->key >= start) {
        addToArray(element->left, array, arraySize, position, start, stop);
    }

    if(element->key >= start && element->key <= stop) {
        /* Increase array size when needed. */
        if(*position >= *arraySize) {
            string *biggerArray = new string[*arraySize * 2];
            *arraySize *= 2;
            for(int i = 0; i < *arraySize; i++)
                biggerArray[i] = (*array)[i];
            delete[] *array;
            *array = biggerArray;
        }

        (*array)[*position] = element->key;
        (*position)++;
    }

    if(element->right && element->key <= stop) {
        addToArray(element->right, array, arraySize, position, start, stop);
    }
}
