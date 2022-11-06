#include "splay_tree.h"

template <typename Comparable>
    SplayTree< Comparable > ::SplayTree( ) {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = nullNode;
    }

template <typename Comparable>
    SplayTree< Comparable > ::~SplayTree( ) {
        makeEmpty( );
        delete nullNode;
    }

template <typename Comparable>
    SplayTree< Comparable > ::SplayTree( const SplayTree & rhs ) {
        nullNode = new BinaryNode;
        nullNode->left = nullNode->right = nullNode;
        root = clone( rhs.root );
    }

template <typename Comparable>
    SplayTree< Comparable > ::SplayTree( SplayTree && rhs ) :
    root{ rhs.root },
    nullNode{ rhs.nullNode } {
        rhs.root = nullptr;
        rhs.nullNode = nullptr;
    }

template <typename Comparable>
    SplayTree< Comparable > & SplayTree< Comparable > ::operator=( const SplayTree & rhs ) {
        SplayTree copy = rhs;
        swap( *this, copy );
        return *this;
    }

template <typename Comparable>
    SplayTree< Comparable > & SplayTree< Comparable > ::operator=( SplayTree && rhs ) {
        swap( root, rhs.root );
        swap( nullNode, rhs.nullNode );
        return *this;
    }

/**
 * Find the smallest item in the tree.
 * Not the most efficient implementation (uses two passes), but has correct
 *     amortized behavior.
 * A good alternative is to first call find with parameter
 *     smaller than any item in the tree, then call findMin.
 * Return the smallest item or throw UnderflowException if empty.
 */
template <typename Comparable>
    const Comparable & SplayTree< Comparable > ::findMin( ) {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }

        BinaryNode *ptr = root;

        while( ptr->left != nullNode ) {
            ptr = ptr->left;
        }

        splay( ptr->element, root );
        return ptr->element;
    }

/**
 * Find the largest item in the tree.
 * Not the most efficient implementation (uses two passes), but has correct
 *     amortized behavior.
 * A good alternative is to first call find with parameter
 *     larger than any item in the tree, then call findMax.
 * Return the largest item or throw UnderflowException if empty.
 */
template <typename Comparable>
    const Comparable & SplayTree< Comparable > ::findMax( ) {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }

        BinaryNode *ptr = root;

        while( ptr->right != nullNode )
            ptr = ptr->right;

        splay( ptr->element, root );
        return ptr->element;
    }

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
    bool SplayTree< Comparable > ::contains( const Comparable & x ) {
        if( isEmpty( ) ) {
            return false;
        }

        splay( x, root );
        return root->element == x;
    }

/**
 * Returns true if root is nullptr
 */
template <typename Comparable>
    bool SplayTree< Comparable > ::isEmpty( ) const {
        return root == nullNode;
    }

template <typename Comparable>
    void SplayTree< Comparable > ::printTree( ostream & out ) const {
        if( isEmpty( ) ) {
            out << "Empty tree" << "\n";
        } else {
            printTree( root, out );
        }
    }

template <typename Comparable>
    void SplayTree< Comparable > ::makeEmpty( ) {
        while( !isEmpty( ) )
        {
            findMax( );        // Splay max item to root
            remove( root->element );
        }
    }

template <typename Comparable>
    void SplayTree< Comparable > ::insert( const Comparable & x ) {
        static BinaryNode *newNode = nullptr;

        if( newNode == nullptr ) {
            newNode = new BinaryNode;
        }
        newNode->element = x;

        if ( root == nullNode ) {
            newNode->left = nullNode;
            newNode->right = nullNode;
            root = newNode;
        } else {
            splay( x, root );

            if ( x < root->element ) {
                newNode->left = root->left;
                newNode->right = root;
                root->left = nullNode;
                root = newNode;
            } else if ( x > root->element ) {
                newNode->right = root->right;
                newNode->left = root;
                root->right = nullNode;
                root = newNode;
            } else {
                return;
            }
            newNode = nullptr; // So next insert will call new
        }
    }

/**
 * If x is found, it will be splayed to the root by contains.
 * 
 */
template <typename Comparable>
    void SplayTree< Comparable > ::remove( const Comparable & x ) {
        if( !contains( x ) ) {
            return;   // Item not found; do nothing
        }

        BinaryNode *newTree;

        if( root->left == nullNode ) {
            newTree = root->right;
        }else {
            // Find the maximum in the left subtree
            // Splay it to the root; and then attach right child
            newTree = root->left;
            splay( x, newTree );
            newTree->right = root->right;
        }

        delete root;
        root = newTree;
    }

/**
 * Internal method to reclaim internal nodes in subtree t.
 * WARNING: This is prone to running out of stack space.
 */
template <typename Comparable>
    void SplayTree< Comparable > ::reclaimMemory( BinaryNode * t ) {
        if( t != t->left )
        {
            reclaimMemory( t->left );
            reclaimMemory( t->right );
            delete t;
        }
    }

/**
 * Internal method to print a subtree t in sorted order.
 * WARNING: This is prone to running out of stack space.
 */
template <typename Comparable>
    void SplayTree< Comparable > ::printTree( BinaryNode *t, ostream & out ) const {
        if( t != t->left )
        {
            printTree( t->left, out );
            out << t->element << "\n";
            printTree( t->right, out );
        }
    }

/**
 * Internal method to clone subtree.
 * WARNING: This is prone to running out of stack space.
 */
template <typename Comparable>
    typename SplayTree<Comparable>::BinaryNode * SplayTree< Comparable > ::clone( BinaryNode * t ) const {
        if( t == t->left )  // Cannot test against nullNode!!!
            return nullNode;
        else
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
    }

/**
 * Rotate binary tree node with left child. Tree manipulation
 * Clockwise rotation
 */
template <typename Comparable>
    void SplayTree< Comparable > ::rotateWithLeftChild( BinaryNode * & k2 ) {
        BinaryNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
    }

/**
 * Rotate binary tree node with left child. Tree manipulation
 * Anticlockwise rotation
 */
template <typename Comparable>
    void SplayTree< Comparable > ::rotateWithRightChild( BinaryNode * & k1 ) {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
    }

template <typename Comparable>
    void SplayTree< Comparable > ::splay( const Comparable & x, BinaryNode * & t ) {
        BinaryNode *leftTreeMax, *rightTreeMin;

        static BinaryNode header;

        header.left = header.right = nullNode;
        leftTreeMax = rightTreeMin = &header;

        nullNode->element = x;   // Guarantee a match

        for( ; ; )  // While Loop
            if( x < t->element )
            {
                if( x < t->left->element )
                    rotateWithLeftChild( t );
                if( t->left == nullNode )
                    break;
                // Link Right
                rightTreeMin->left = t;
                rightTreeMin = t;
                t = t->left;
            }
            else if( t->element < x )
            {
                if( t->right->element < x )
                    rotateWithRightChild( t );
                if( t->right == nullNode )
                    break;
                // Link Left
                leftTreeMax->right = t;
                leftTreeMax = t;
                t = t->right;
            }
            else
                break;

        leftTreeMax->right = t->left;
        rightTreeMin->left = t->right;
        t->left = header.right;
        t->right = header.left;
    }
