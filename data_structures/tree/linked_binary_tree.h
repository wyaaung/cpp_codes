#include <iostream>
#include <list>

/*
 * Binary Tree is proper/ full if each node has either zero or two children.
 * 
 * Perfect Binary Tree is a binary tree in which every internal node has exactly two children, 
 * and all the leaf nodes are at the same level.
 * 
 * Balanced Binary Tree is a binary tree in which 
 * the left and right subtrees of every node differ in height by no more than 1.
 * 
 * A binary tree composed of an array has an index value of 
 * parent(i) = i/2, left_child(i) = 2i, right_child(i) = 2i + 1 for the i-th node where
 * the number of nodes is n and root starts at non-zero 1.
*/

using namespace std;

template < typename T >
    class LinkedBinaryTree {
        protected:
            struct Node {
                T value;
                Node *parent;
                Node *left;
                Node *right;
                Node();
            };
        public:
            class Position {        // Position in the Tree
                private:
                    Node *pointer;        // Pointer to the node
                public:
                    Position(Node *u);      // Constructor

                    T& operator*();

                    /* Get Left, Right children and Parent O(1) */
                    Position left() const;
                    Position right() const;
                    Position parent() const;

                    bool isRoot() const;

                    bool isExternal() const;

                    friend class LinkedBinaryTree<T>;
            };

            typedef list<Position> PositionList;
        public:
            LinkedBinaryTree(); // constructor

            int size() const; // number of nodes

            bool empty() const; // is tree empty?

            Position root() const; // get the root

            PositionList positions() const; // list of nodes O(n)

            void addRoot(); // add root to empty tree

            /* Expand external node: visit only a constant number of nodes O(1) */
            void expandExternal(const Position& p);

            /* Remove p and parent: visit only a constant number of nodes O(1) */
            Position removeAboveExternal(const Position& p);
        protected: // local utilities
            void preOrder(Node* v, PositionList& pl) const;     // Pre Order utility O(n)
        private:
            Node* rootNode; // pointer to the root

            int n; // number of nodes
    };
