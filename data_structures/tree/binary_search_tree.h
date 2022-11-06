#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <algorithm>

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

struct UnderFlowException: public runtime_error {
    UnderFlowException(const char * msg): runtime_error(msg) {}
};

// BinarySearchTree class
//
// CONSTRUCTION: zero parameter
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
    class BinarySearchTree {
        public:
            BinarySearchTree( );

            ~BinarySearchTree( );

            /* Copy Constructor and Copy Assignemnt Operator */
            BinarySearchTree( const BinarySearchTree & rhs );
            BinarySearchTree & operator=( const BinarySearchTree & rhs );

            /* Move Constructor and Move Assignemnt Operator */
            BinarySearchTree( BinarySearchTree && rhs );
            BinarySearchTree & operator=( BinarySearchTree && rhs );

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
            struct BinaryNode {
                Comparable element;
                BinaryNode *left;
                BinaryNode *right;

                BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ theElement }, left{ lt }, right{ rt } { }

                BinaryNode( Comparable && theElement, BinaryNode *lt, BinaryNode *rt )
                : element{ move( theElement ) }, left{ lt }, right{ rt } { }
            };

            BinaryNode *root;

            /**
             * Several of the private member functions use the technique of passing a pointer variable
             * using call-by-reference. This allows the public member functions to pass a pointer to the
             * root to the private recursive member functions. 
             * 
             * The recursive functions can then change 
             * the value of the root so that the root points to another node
             */
            void insert( const Comparable & x, BinaryNode * & t );
            void insert( Comparable && x, BinaryNode * & t );

            void remove( const Comparable & x, BinaryNode * & t );

            BinaryNode * findMin( BinaryNode *t ) const;
            BinaryNode * findMax( BinaryNode *t ) const;

            bool contains( const Comparable & x, BinaryNode *t ) const;
            void makeEmpty( BinaryNode * & t );

            void printTree( BinaryNode *t, ostream & out ) const;
            BinaryNode * clone( BinaryNode *t ) const;
    };

#endif
