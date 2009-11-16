#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <string>

/** A binary tree that is actually a treemap.
 */
template<class K, class T>
class BinarySearchTree
{
    public:
        /** 
         * Constructor.
         */
        BinarySearchTree();

        /** 
         * Destructor.
         */
        ~BinarySearchTree();

        /**
         * Insert an element into the tree. If an element with the given
         * key already exists, this action will be ignored.
         * @param key Key to insert.
         * @param value Value to insert.
         */
        void put(const K &key, const T &value);

        /** 
         * Check if a certain key exists in the tree.
         * @param key Key to check.
         * @return If this tree contains the key.
         */
        bool contains(const K &key);

        /**
         * Get a certain value from the tree.
         * @param key Key to check.
         * @return Value of the associated key.
         */
        const T &get(const K &key);

    protected:
        /**
         * An element in the tree.
         */
        class TreeElement
        {
            public:
                /** Related elements. */
                TreeElement *left, *right, *parent;

                /** Key. */
                K key;

                /** Value. */
                T value;

                /**
                 * Constructor.
                 */
                TreeElement(const K &key, const T &value);

                /**
                 * Destructor.
                 */
                ~TreeElement();
        };

        /**
         * Get the position of an element.
         * @param key Key to get the associated element for.
         * @return A reference to the requested element.
         */
        typename BinarySearchTree::TreeElement **find(const K &key);

    private:
        /** Root of the tree. */
        TreeElement *root;
};

#endif
