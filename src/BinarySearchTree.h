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

                /** Constructor. */
                TreeElement(const K &key, const T &value);

                /** Destructor. */
                ~TreeElement();
        };

    private:
        /** Root of the tree. */
        TreeElement *root;

    protected:
        /**
         * Get the position of an element.
         */
        TreeElement **get(const K &key);

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
        void insert(const K &key, const T &value);
};

#endif
