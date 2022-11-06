#include "avl_tree.h"

/**
 * Constructor
 */
template <typename Comparable>
    AVLTree< Comparable > ::AVLTree( ) {
        root = nullptr;
    }

/**
 *  Destructor for the Binary Search Tree
 */
template <typename Comparable>
    AVLTree< Comparable > ::~AVLTree( ) {
        makeEmpty();
    }

/**
 * Copy Constructor
 */
template <typename Comparable>
    AVLTree< Comparable > ::AVLTree( const AVLTree & rhs ) :
    root{ nullptr } {
        root = clone( rhs.root );
    }

/**
 * Copy Assignment Operator
 */
template <typename Comparable>
    AVLTree< Comparable > & AVLTree< Comparable > ::operator=( const AVLTree & rhs ) {
        makeEmpty( );
        root = clone( rhs.root );
    }

/**
 * Move Constructor
 */
template <typename Comparable>
    AVLTree< Comparable > ::AVLTree( AVLTree && rhs ) :
    root{ move( root ) }{ }

/**
 * Move Assignment Operator
 */
template <typename Comparable>
    AVLTree< Comparable > & AVLTree< Comparable > ::operator=( AVLTree && rhs ) {
        makeEmpty( );
        root = move( rhs.root );
    }

/**
 * Return node containing the smallest item.
 */
template <typename Comparable>
    const Comparable & AVLTree< Comparable > ::findMin( ) const {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }
        return findMin( root )->element;
    }

/**
 * Return node containing the largest item.
 */
template <typename Comparable>
    const Comparable & AVLTree< Comparable > ::findMax( ) const {
        if( isEmpty( ) ) {
            throw UnderFlowException("Under FLOW EXCEPTION");
        }
        return findMax( root )->element;
    }

/**
 * Returns true if x is found in the tree.
 */
template <typename Comparable>
    bool AVLTree< Comparable > ::contains( const Comparable & x ) const {
        return contains(x, root);
    }

/**
 * Returns true if root is nullptr
 */
template <typename Comparable>
    bool AVLTree< Comparable > ::isEmpty( ) const {
        return root == nullptr;
    }

/**
 * Print the tree contents in sorted order.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::printTree( ostream & out ) const {
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
    void AVLTree< Comparable > ::makeEmpty( ) {
        makeEmpty( root );
    }


/**
 *  Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::insert( const Comparable & x ) {
        return insert(x, root);
    }

/**
 *  Insert x into the tree by moving x; duplicates are ignored.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::insert( Comparable && x ) {
        return insert( move(x), root );
    }

/**
 *  Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::remove( const Comparable & x ) {
        return remove(x, root);
    }

/****************** Internal Methods ******************/

/**
 * @param t the node that roots the subtree
 * @return the height of the node or -1 if the subtree t is nullptr
 */
template <typename Comparable>
    int AVLTree< Comparable > ::height( AVLNode *t ) const {
        return ( t == nullptr ? -1 : t->height );
    }

/**
 * Internal method to insert into a subtree.
 * 
 * Set the new root of the subtree.
 * @param x the item to insert.
 * @param t the node that roots the subtree.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::insert( const Comparable & x, AVLNode * & t ) {
        if (t == nullptr) {
            t = new AVLNode{ x, nullptr, nullptr };
        } else if ( x < t -> element ) {
            insert( x, t -> left );
        } else if ( x > t -> element ) {
            insert( x, t -> right );
        } 

        balance( t );
    }

/**
 * Internal method to insert into a subtree.
 * 
 * Set the new root of the subtree.
 * @param x the item to insert by moving.
 * @param t the node that roots the subtree.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::insert( Comparable && x, AVLNode * & t ) {
        if (t == nullptr) {
            t = new AVLNode{ move(x), nullptr, nullptr };
        } else if ( x < t -> element ) {
            insert( move(x), t -> left );
        } else if ( x > t -> element ) {
            insert( move(x), t -> right );
        } 

        balance( t );
    }

/**
 * @brief Balancing the Tree with assumption that t is balanced.
 */
template <typename Comparable>
    void AVLTree< Comparable > ::balance( AVLNode *&t ) {
        if (t == nullptr) return;

        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE ) {
            if ( height( t->left ->left) >= height( t->left->right ) ) {
                rotateWithLeftChild( t );
            } else {
                doubleWithLeftChild( t );
            }
        } else if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE ){
            if( height( t->right->right ) >= height( t->right->left ) ) {
                rotateWithRightChild( t );
            } else {
                doubleWithRightChild( t );
            }
        }

        t->height = max( height( t->left ), height( t->right ) ) + 1;
    }

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root
 * 
 * Clockwise right rotation
 */
template <typename Comparable>
    void AVLTree< Comparable > ::rotateWithLeftChild( AVLNode * & k2 ) {
        AVLNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;
        k1->height = max( height( k1->left ), k2->height ) + 1;
        k2 = k1;
    }

/**
 * @brief Rotate binary tree node with right child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root
 * 
 * Clockwise left rotation
 */
template <typename Comparable>
    void AVLTree< Comparable > ::rotateWithRightChild( AVLNode * & k1) {
        AVLNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
        k2->height = max( height( k2->left ), k1->height ) + 1;
        k1 = k2;
    }

/**
 * Double rotate binary tree node: first left child
 * with its right child; then node k3 with new left child
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 * 
 * Clockwise left rotation on left child, then
 * Clockwise right rotation on its node
 */
template <typename Comparable>
    void AVLTree< Comparable > ::doubleWithLeftChild( AVLNode * & k3 ) {
        rotateWithRightChild( k3->left );
        rotateWithLeftChild( k3 );
    }

/**
 * Double rotate binary tree node: first right child
 * with its left child; then node k1 with new right child
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 *
 * Clockwise right rotation on right child, then
 * Clockwise left rotation on its node
 */
template <typename Comparable>
    void AVLTree< Comparable > ::doubleWithRightChild( AVLNode * & k1 ) {
        rotateWithLeftChild( k1->right );
        rotateWithRightChild( k1 );
    }

/**
 * Internal method to remove from a subtree.
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
    void AVLTree< Comparable > ::remove( const Comparable & x, AVLNode * & t ) {
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
            AVLNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }

        balance( t );
    }

/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
template <typename Comparable>
    typename AVLTree<Comparable>::AVLNode * AVLTree< Comparable > ::findMin( AVLNode *t ) const {
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
    typename AVLTree< Comparable > ::AVLNode * AVLTree< Comparable > ::findMax( AVLNode *t ) const {
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
    bool AVLTree< Comparable > ::contains( const Comparable & x, AVLNode *t ) const {
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
    void AVLTree< Comparable > ::makeEmpty( AVLNode * & t ){
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
    void AVLTree< Comparable > ::printTree( AVLNode *t, ostream & out ) const {
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
    typename AVLTree<Comparable>::AVLNode * AVLTree< Comparable > ::clone( AVLNode *t ) const {
        if ( t == nullptr ) {
            return nullptr;
        } else {
            return new AVLNode{ t->element, clone( t->left ), clone( t->right ) };
        }
    }
