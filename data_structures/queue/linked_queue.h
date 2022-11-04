#include <iostream>
#include <stdexcept>

using namespace std;

struct QueueEmpty : public runtime_error
{
    QueueEmpty(const char* msg) : runtime_error(msg) {}
};

template <typename T>
class CircularlyLinkedList;

template <typename T>
class Node {
    private:
        T value;
        Node<T> *next;

        // A friend class can access private and protected members of other class 
        // in which it is declared as friend.
        friend class CircularlyLinkedList<T>;
    public:
        Node();
        Node(T value);
};

template <typename T>
class CircularlyLinkedList {
    private:
        Node<T> *cursor;
    
    public:
        CircularlyLinkedList();

        ~CircularlyLinkedList();

        bool empty() const;         // is list empty?

        const T& head() const;      // get head node

        const T& tail() const;       // get tail node

        void advance();             // advance cursor

        void add(const T& value);   // add after cursor
        /* Remove the node after cursor, not the cursor itself
            unless it is the only node; if the list becomes empty,
            the cursor is set to null. */
        void remove();
};

template <typename T>
class LinkedQueue {
    private:
        CircularlyLinkedList<T> *circularlyLinkedList;
        int n;
    public:
        LinkedQueue();

        ~LinkedQueue();

        int size() const;

        bool empty() const;

        const T& front() const throw(QueueEmpty);

        void enqueue(const T& value);

        void dequeue() throw(QueueEmpty);
};
