#include "list.h"

template < typename T >
    NodeList < T > ::Iterator::Iterator(Node * u) {
        this -> pointer = u;
    }

template < typename T >
    T & NodeList < T > ::Iterator::operator * () {
        return this -> pointer -> value;
    }

template < typename T >
    bool NodeList < T > ::Iterator::operator == (const Iterator & p) const {
        return (this -> pointer == p.pointer);
    }

template < typename T >
    bool NodeList < T > ::Iterator::operator != (const Iterator & p) const {
        return (this -> pointer != p.pointer);
    }

template < typename T >
    typename NodeList < T > ::Iterator & NodeList < T > ::Iterator::operator++() {
        this -> pointer = this -> pointer -> next;
        return *this;
    }

template < typename T >
    typename NodeList < T > ::Iterator & NodeList < T > ::Iterator::operator++(int) {
        Iterator copy( * this);
        this -> pointer = this -> pointer -> next;
        return copy;
    }

template < typename T >
    typename NodeList < T > ::Iterator & NodeList < T > ::Iterator::operator--() {
        this -> pointer = this -> pointer -> prev;
        return *this;
    }

template < typename T >
    typename NodeList < T > ::Iterator & NodeList < T > ::Iterator::operator--(int) {
        Iterator copy( * this);
        this -> pointer = this -> pointer -> prev;
        return copy;
    }

template < typename T >
    NodeList < T > ::NodeList() {
        this -> n = 0; // Initially Empty

        this -> header = new Node;
        this -> trailer = new Node;

        this -> header -> next = this -> trailer;
        this -> trailer -> prev = this -> header;
    }

template < typename T >
    int NodeList < T > ::size() const {
        return this -> n;
    }

template < typename T >
    bool NodeList < T > ::empty() const {
        return (n == 0);
    }

template < typename T >
    typename NodeList < T > ::Iterator NodeList < T > ::begin() const {
        return Iterator(this -> header -> next);
    }

template < typename T >
    typename NodeList < T > ::Iterator NodeList < T > ::end() const {
        return Iterator(this -> trailer -> prev);
    }

template < typename T >
    void NodeList < T > ::insert(const Iterator & p,
        const T & value) {
        Node * pNode = p.pointer; // P's Node

        Node * pNodePrev = pNode -> prev;

        Node * newNode = new Node; // New Node

        newNode -> value = value;
        newNode -> next = pNode;
        pNode -> prev = newNode;
        newNode -> prev = pNodePrev;
        pNodePrev -> next = newNode;

        this -> n++;
    }

template < typename T >
    void NodeList < T > ::insertFront(const T & value) {
        insert(begin(), value);
    }

template < typename T >
    void NodeList < T > ::insertBack(const T & value) {
        insert(end(), value);
    }

template < typename T >
    void NodeList < T > ::erase(const Iterator & p) {
        /* Remove p */

        Node * pNode = p.pointer;

        Node * pNodeNext = pNode -> next;
        Node * pNodePrev = pNode -> prev;

        pNodePrev -> next = pNodeNext;
        pNodeNext -> prev = pNodePrev;

        delete pNode;
        n--;
    }

template < typename T >
    void NodeList < T > ::eraseBack() {
        erase(--end());
    }

template < typename T >
    void NodeList < T > ::eraseFront() {
        erase(begin());
    }
