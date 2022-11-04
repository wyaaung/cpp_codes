#include "linked_binary_tree.h"

template < typename T >
    LinkedBinaryTree < T > ::Node::Node() {
        this -> parent = nullptr;
        this -> left = nullptr;
        this -> right = nullptr;
    }

template < typename T >
    LinkedBinaryTree < T > ::Position::Position(Node * u) {
        this -> pointer = u;
    }

template < typename T >
    T & LinkedBinaryTree < T > ::Position::operator * () {
        return this -> pointer -> value;
    }

template < typename T >
    typename LinkedBinaryTree < T > ::Position LinkedBinaryTree < T > ::Position::left() const {
        return Position(this -> pointer -> left);
    }

template < typename T >
    typename LinkedBinaryTree < T > ::Position LinkedBinaryTree < T > ::Position::right() const {
        return Position(this -> pointer -> right);
    }

template < typename T >
    typename LinkedBinaryTree < T > ::Position LinkedBinaryTree < T > ::Position::parent() const {
        return Position(this -> pointer -> parent);
    }

template < typename T >
    bool LinkedBinaryTree < T > ::Position::isRoot() const {
        return (this -> pointer -> parent == nullptr);
    }

template < typename T >
    bool LinkedBinaryTree < T > ::Position::isExternal() const {
        return (this -> pointer -> left == nullptr && this -> pointer -> right == nullptr);
    }

template < typename T >
    LinkedBinaryTree < T > ::LinkedBinaryTree() {
        this -> rootNode = nullptr;
        this -> n = 0;
    }

template < typename T >
    int LinkedBinaryTree < T > ::size() const {
        return this -> n;
    }

template < typename T >
    bool LinkedBinaryTree < T > ::empty() const {
        return size() == 0;
    }

template < typename T >
    typename LinkedBinaryTree < T > ::Position LinkedBinaryTree < T > ::root() const {
        return LinkedBinaryTree < T > ::Position(this -> rootNode);
    }

template < typename T >
    void LinkedBinaryTree < T > ::addRoot() {
        this -> rootNode = new Node;
        this -> n = 1;
    }

template < typename T >
    void LinkedBinaryTree < T > ::expandExternal(const Position & p) {
        Node * pNode = p.pointer; // P's node

        /* Add new left and right children */
        pNode->left = new Node();
        pNode->left->parent = pNode;
        pNode->right = new Node();
        pNode->right->parent = pNode;

        this->n += 2;
    }

template < typename T >
    typename LinkedBinaryTree < T > ::Position LinkedBinaryTree < T > ::removeAboveExternal(const Position & p) {
        /**
         * Remove the external node p together with its parent q,
         * replacing q with the sibling of p;
         * 
         * an error condition occurs
         * if p is an internal node or p is the root.
         */
        Node * pNode = p.pointer; // P's node

        Node * pNodeParent = pNode->parent; // P's Node Parent

        Node * sib = (pNode == pNodeParent->left ? pNode->right : pNode->left);

        if (pNodeParent == this->rootNode) {
            this->rootNode = sib;
            sib->parent = nullptr;
        } else {
            Node *pNodeGParent = pNodeParent->parent; // P's Node GrandParent

            if (pNodeParent == pNodeGParent->left) {
                pNodeGParent->left = sib;
            } else {
                pNodeGParent->right = sib;
            }

            sib->parent = pNodeGParent;
        }

        delete pNode;
        delete pNodeParent;

        return Position(sib);
    }

template < typename T >
    void LinkedBinaryTree < T > ::preOrder(Node *v, PositionList &pl) const {
        /**
         * Root is visited first, and then the subtrees rooted at its children are traversed recursively
         */
        pl.push_back(Position(v));      // Add this node

        if (v->left != nullptr) {
            preorder(v->left, pl);
        }

        if (v->right != nullptr) {
            preorder(v->right, pl);
        }
    }

template < typename T >
    typename LinkedBinaryTree < T > ::PositionList LinkedBinaryTree < T > ::positions() const {
        PositionList pl;

        preOrder(this->rootNode, pl);       // Pre Order Traversal

        return PositionList(pl);
    }


