#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <algorithm>

/**
 * @brief Self Balancing Tree - AVL Tree is identical to a binary search tree,
 * except that for every node in the tree,
 * the height of the left and right subtrees can differ by at most 1
 * 
 * To maintain a bound of O(log N) for height -> Balance condition must be maintain.
 * every node must have left and right subtrees of the same height. 
 * 
 */

using namespace std;

struct UnderFlowException: public runtime_error {
    UnderFlowException(const char * msg): runtime_error(msg) {}
};

// AvlTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x (unimplemented)
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
    class AVLTree {
        public:
            AVLTree( );

            ~AVLTree( );

            /* Copy Constructor and Copy Assignemnt Operator */
            AVLTree( const AVLTree & rhs );
            AVLTree & operator=( const AVLTree & rhs );

            /* Move Constructor and Move Assignemnt Operator */
            AVLTree( AVLTree && rhs );
            AVLTree & operator=( AVLTree && rhs );

            const Comparable & findMin( ) const;
            const Comparable & findMax( ) const;

            bool contains( const Comparable & x ) const;
            bool isEmpty( ) const;
            void printTree( ostream & out = cout ) const;

            void makeEmpty( );
            void insert( const Comparable & x );
            void insert( Comparable && x );
            void remove( const Comparable & x );

        private:
            struct AVLNode {
                Comparable element;
                AVLNode *left;
                AVLNode *right;
                int height;

                AVLNode( const Comparable & theElement, AVLNode *lt, AVLNode *rt, int h = 0 )
                : element{ theElement }, left{ lt }, right{ rt }, height { h } { }

                AVLNode( Comparable && theElement, AVLNode *lt, AVLNode *rt, int h = 0 )
                : element{ move( theElement ) }, left{ lt }, right{ rt }, height{ h } { }
            };

            AVLNode *root;

            static const int ALLOWED_IMBALANCE = 1;

            /**
             * Several of the private member functions use the technique of passing a pointer variable
             * using call-by-reference. This allows the public member functions to pass a pointer to the
             * root to the private recursive member functions. 
             * 
             * The recursive functions can then change 
             * the value of the root so that the root points to another node
             */

            int height( AVLNode *t ) const;

            void insert( const Comparable & x, AVLNode * & t );
            void insert( Comparable && x, AVLNode * & t );

            // Assume t is balanced or within one of being balanced.
            void balance( AVLNode *&t );

            // Case 1: the left subtree of the left child 
            void rotateWithLeftChild( AVLNode * & k2 );
            // Case 4: the right subtree of the right child
            void rotateWithRightChild( AVLNode * & k1 );
            // Case 2: the right subtree of the left child
            void doubleWithLeftChild( AVLNode * & k3 );
            // Case 3: the left subtree of the right child
            void doubleWithRightChild( AVLNode * & k1 );

            void remove( const Comparable & x, AVLNode * & t );

            AVLNode * findMin( AVLNode *t ) const;
            AVLNode * findMax( AVLNode *t ) const;

            bool contains( const Comparable & x, AVLNode *t ) const;
            void makeEmpty( AVLNode * & t );

            void printTree( AVLNode *t, ostream & out ) const;
            AVLNode * clone( AVLNode *t ) const;
    };

#endif
