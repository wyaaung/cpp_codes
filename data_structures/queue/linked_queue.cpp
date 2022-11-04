#include "linked_queue.h"

template < typename T >
    Node < T > ::Node() {
        this -> next = nullptr;
    }

template < typename T >
    Node < T > ::Node(T value) {
        this -> value = value;
        this -> next = nullptr;
    }

template < typename T >
    CircularlyLinkedList < T > ::CircularlyLinkedList() {
        this -> cursor = nullptr;
    }

template < typename T >
    CircularlyLinkedList < T > ::~CircularlyLinkedList() {
        while (!empty()) {
            remove();
        }
    }

template < typename T >
    bool CircularlyLinkedList < T > ::empty() const {
        return (this -> cursor == nullptr);
    }

template < typename T >
    const T & CircularlyLinkedList < T > ::head() const {
        /* Value following cursor */
        return this -> cursor -> next -> value;
    }

template < typename T >
    const T & CircularlyLinkedList < T > ::tail() const {
        /* Value at cursor*/
        return this -> cursor -> value;
    }

template < typename T >
    void CircularlyLinkedList < T > ::advance() {
        this -> cursor = this -> cursor -> next;
    }

template < typename T >
    void CircularlyLinkedList < T > ::add(const T & value) {
        Node < T > * newNode = new Node < T > (value);

        if (this -> cursor == NULL) {
            /* newNode points to itself, cursor points to newNode*/
            newNode -> next = newNode;
            cursor = newNode;
        } else {
            /* Insert a node just after a cursor */
            newNode -> next = this -> cursor -> next;
            cursor -> next = newNode;
        }
    }

template < typename T >
    void CircularlyLinkedList < T > ::remove() {
        Node < T > * oldNode = this -> cursor -> next;

        if (oldNode == this -> cursor) {
            this -> cursor = nullptr;
        } else {
            this -> cursor -> next = oldNode -> next;
        }

        delete oldNode;
    }

template < typename T >
    LinkedQueue < T > ::LinkedQueue() {
        this -> circularlyLinkedList = new CircularlyLinkedList < T > ();
        this -> n = 0;
    }

template < typename T >
    int LinkedQueue < T > ::size() const {
        return this -> n;
    }

template < typename T >
    bool LinkedQueue < T > ::empty() const {
        return (this -> n == 0);
    }

template < typename T >
    const T & LinkedQueue < T > ::front() const
throw (QueueEmpty) {
    if (empty()) {
        throw QueueEmpty("front of Empty Queue");
    }

    this -> circularlyLinkedList -> head();
}

template < typename T >
    void LinkedQueue < T > ::enqueue(const T & value) {
        this -> circularlyLinkedList -> add(value);
        this -> circularlyLinkedList -> advance();
        this -> n++;
    }

template < typename T >
    void LinkedQueue < T > ::dequeue() throw (QueueEmpty) {
        if (empty()) {
            throw QueueEmpty("deque of Empty Queue");
        }
        this -> circularlyLinkedList -> remove();
        this -> n--;
    }
