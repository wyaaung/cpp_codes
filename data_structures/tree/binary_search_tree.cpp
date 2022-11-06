#include "binary_search_tree.h"

/**
 * Constructor
 */
template <typename Comparable>
    BinarySearchTree< Comparable > ::BinarySearchTree( ) {
        root = nullptr;
    }

/**
 *  Destructor for the Binary Search Tree
 */
template <typename Comparable>
    BinarySearchTree< Comparable > ::~BinarySearchTree( ) {
        makeEmpty();
    }

/**
 * Copy Constructor
 */
template <typename Comparable>
    BinarySearchTree< Comparable > ::BinarySearchTree( const BinarySearchTree & rhs ) :
    root{ nullptr } {
        root = clone( rhs.root );
    }

/**
 * Copy Assignment Operator
 */
template <typename Comparable>
    BinarySearchTree< Comparable > & BinarySearchTree< Comparable > ::operator=( const BinarySearchTree & rhs ) {
        makeEmpty( );
        root = clone( rhs.root );
    }

/**
 * Move Constructor
 */
template <typename Comparable>
    BinarySearchTree< Comparable > ::BinarySearchTree( BinarySearchTree && rhs ) :
    root{ move( root ) }{ }

/**
 * Move Assignment Operator
 */
template <typename Comparable>
    BinarySearchTree< Comparable > & BinarySearchTree< Comparable > ::operator=( BinarySearchTree && rhs ) {
        makeEmpty( );
        root = move( rhs.root );
    }

/**
 * Return node containing the smallest item.
 */
template <typename Comparable>
    const Comparable & BinarySearchTree< Comparable > ::findMin( ) const {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }
        return findMin( root )->element;
    }

/**
 * Return node containing the largest item.
 */
template <typename Comparable>
    const Comparable & BinarySearchTree< Comparable > ::findMax( ) const {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }
        return findMax( root )->element;
    }

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
    bool BinarySearchTree< Comparable > ::contains( const Comparable & x ) const {
        return contains(x, root);
    }

/**
 * Returns true if root is nullptr
 */
template <typename Comparable>
    bool BinarySearchTree< Comparable > ::isEmpty( ) const {
        return root == nullptr;
    }

/**
 * Print the tree contents in sorted order.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::printTree( ostream & out ) const {
        if( isEmpty( ) ) {
            out << "Empty tree" << "\n";
        } else {
            printTree( root, out );
        }
    }

/**
 * At the end, root will be changed to nullptr
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::makeEmpty( ) {
        makeEmpty( root );
    }


/**
 *  Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::insert( const Comparable & x ) {
        return insert(x, root);
    }

/**
 *  Insert x into the tree by moving x; duplicates are ignored.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::insert( Comparable && x ) {
        return insert( move(x), root );
    }

/**
 *  Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::remove( const Comparable & x ) {
        return remove(x, root);
    }

/****************** Internal Methods ******************/

/**
 * @brief Internal method to insert into a subtree.
 * 
 * Set the new root of the subtree.
 * @param x the item to insert.
 * @param t the node that roots the subtree.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::insert( const Comparable & x, BinaryNode * & t ) {
        if (t == nullptr) {
            t = new BinaryNode{ x, nullptr, nullptr };
        } else if ( x < t -> element ) {
            insert( x, t -> left );
        } else if ( x > t -> element ) {
            insert( x, t -> right );
        } else {
            return;
        }
    }

/**
 * @brief Internal method to insert into a subtree.
 * 
 * Set the new root of the subtree.
 * @param x the item to insert by moving.
 * @param t the node that roots the subtree.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::insert( Comparable && x, BinaryNode * & t ) {
        if (t == nullptr) {
            t = new BinaryNode{ move(x), nullptr, nullptr };
        } else if ( x < t -> element ) {
            insert( move(x), t -> left );
        } else if ( x > t -> element ) {
            insert( move(x), t -> right );
        } else {
            return;
        }
    }

/**
 * @brief  Internal method to remove from a subtree.
 * 
 * @param x  is the item to remove.
 * @param t  is the node that roots the subtree.
 * Set the new root of the subtree.
 * 
 * For a node with two children
 * replace the data of this node with the smallest data of the right subtree
 * and recursively delete that node
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::remove( const Comparable & x, BinaryNode * & t ) {
        if (t == nullptr) {
            return;
        }

        if (x < t->element) {
            remove( x, t->left);
        } else if ( x > t->element ) {
            remove( x, t->right);
        } else if ( t->left != nullptr && t->right != nullptr ) {
            t->element = findMin(t->right)->element;
            remove( t->element, t->right );
        } else {
            BinaryNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
    }

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
    typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree< Comparable > ::findMin( BinaryNode *t ) const {
        if (t == nullptr) {
            return nullptr;
        }

        if (t->left == nullptr) {
            return nullptr;
        }

        return findMin( t->left );
    }

/**
 * Internal method to find the largest item in a subtree t.
 * Return node containing the largest item.
 * 
 * Only working with a copy of a pointer
 */
template <typename Comparable>
    typename BinarySearchTree< Comparable > ::BinaryNode * BinarySearchTree< Comparable > ::findMax( BinaryNode *t ) const {
        if (t != nullptr) {
            while (t->right != nullptr) {
                t = t->right;
            }
        }

        return t;
    }

/**
 *  Internal method to test if an item is in a subtree.
 *  x is item to search for.
 *  t is the node that roots the subtree.
 */
template <typename Comparable>
    bool BinarySearchTree< Comparable > ::contains( const Comparable & x, BinaryNode *t ) const {
        /* O(log N) */
        if (t == nullptr) {         // Check for an empty tree be performed
            return false;
        } else if (x < t->element) {
            return contains( x, t->left );
        } else if (x > t->element){
            return contains( x, t->right );
        } else {
            return true;
        }
    }

/**
 * Internal method to make subtree empty
 * 
 * At the end, t will be changed to nullptr
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::makeEmpty( BinaryNode * & t ){
        if( t != nullptr ) {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }
/**
 * Inorder Traversal of BST
 * Internal method to print a subtree rooted at t in sorted order.
 */
template <typename Comparable>
    void BinarySearchTree< Comparable > ::printTree( BinaryNode *t, ostream & out ) const {
        if( t != nullptr ) {
            printTree( t->left, out );
            out << t->element << "\n";
            printTree( t->right, out );
        }
    }

/**
 * Internal method to clone subtree
 */
template <typename Comparable>
    typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree< Comparable > ::clone( BinaryNode *t ) const {
        if ( t == nullptr ) {
            return nullptr;
        } else {
            return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
        }
    }
