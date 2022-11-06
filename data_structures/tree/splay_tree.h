#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <iostream>
#include <algorithm>

using namespace std;

struct UnderFlowException: public runtime_error {
    UnderFlowException(const char * msg): runtime_error(msg) {}
};

// SplayTree class
//
// CONSTRUCTION: with no parameters
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// bool isEmpty( )        --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename Comparable>
class SplayTree {
    public:
        SplayTree( );

        ~SplayTree( );

        /* Copy Constructor */
        SplayTree( const SplayTree & rhs );

        /* Move Constructor*/
        SplayTree( SplayTree && rhs );

        /* Copy Assignment Operator ( Deep Copy )*/
        SplayTree & operator=( const SplayTree & rhs );

        /* Move Constructor */
        SplayTree & operator=( SplayTree && rhs );

        const Comparable & findMin( );
        const Comparable & findMax( );

        bool contains( const Comparable & x );
        bool isEmpty( ) const;

        void makeEmpty( );
        void insert( const Comparable & x );
        void remove( const Comparable & x );
        void printTree( ostream & out = cout ) const;

    private:
        struct BinaryNode {
            Comparable element;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode( ) : left{ nullptr }, right{ nullptr } { }

            BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element{ theElement }, left{ lt }, right{ rt } { }
        };

        BinaryNode *root;
        BinaryNode *nullNode;

        void reclaimMemory( BinaryNode * t );
        void printTree( BinaryNode *t, ostream & out ) const;

        BinaryNode * clone( BinaryNode * t ) const;

        void rotateWithLeftChild( BinaryNode * & k2 );
        void rotateWithRightChild( BinaryNode * & k1 );

        /**
         * Internal method to perform a top-down splay.
         * The last accessed node becomes the new root.
         * This method may be overridden to use a different
         * splaying algorithm, however, the splay tree code
         * depends on the accessed item going to the root.
         * x is the target item to splay around.
         * t is the root of the subtree to splay.
         */
        void splay( const Comparable & x, BinaryNode * & t );
};

#endif
