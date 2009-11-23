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
         * Remove an element from the tree.
         * @param key Key to remove.
         */
        void remove(const K &key);

        /**
         * Get a certain value from the tree.
         * @param key Key to check.
         * @return Pointer to value of the associated key. NULL if not found.
         */
        T *get(const K &key);

        /**
         * Get all values from the tree.
         * @param arraySize Will contain the size of the returned array.
         * @return All values from the tree.
         */
        T *getAllValues(int &arraySize) const;

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

                /**
                 * Set left child, and parent of left child.
                 * @param left New left child.
                 */
                void setLeft(TreeElement *left);

                /**
                 * Set right child, and parent of right child.
                 * @param right New right child.
                 */
                void setRight(TreeElement *right);
        };

        /**
         * Get the position of an element.
         * @param key Key to get the associated element for.
         * @param parent Will contain the parent of the found node.
         * @return The requested element.
         */
        TreeElement *find(const K &key, TreeElement **parent);

        /**
         * Splay the node once.
         * @param lower Lower of the three nodes to splay.
         * @return Next node to splay, NULL if reached root.
         */
        TreeElement *splayOnce(TreeElement *lower);

        /**
         * Splay the entire tree.
         * @param node Node to start from.
         */
        void splay(TreeElement *node);

        /**
         * Set the root of this rree.
         * @param root The new root.
         */
        void setRoot(TreeElement *node);

        /**
         * Used to recursively obtain all values in the tree.
         * @param array To put the elements in.
         * @param position Current position in the array.
         * @param node Current position the the tree.
         */
        void getAllValues(T *array, int &position, TreeElement *node) const;

    private:
        /** Root of the tree. */
        TreeElement *root;

        /** Size of the tree. */
        int size;
};

#endif
