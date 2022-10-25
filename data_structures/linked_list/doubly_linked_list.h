#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T value;
        Node<T> *next, *prev;

        // A friend class can access private and protected members of other class 
        // in which it is declared as friend.
        friend class DoublyLinkedList;
    public:
        Node(T value);
        Node(T value, Node<T> *&next, Node<T> *&prev);
};

template<class T> void swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

// Doubly Linked List 
template <typename T>
class DoublyLinkedList {
    private:
        int size = 0;

        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

    public:
        DoublyLinkedList();         // Constructor

        ~DoublyLinkedList();        // Destructor

        bool empty() const;         // is list empty?

        const T& head() const;      // get head node

        const T& tail() const;       // get tail node

        // Get read access to node, but cannot modify its value (becuz of const).
        // Thread Safe
        void addFront(const T& value);   // add to the head of list

        void addBack(const T& value);    // add to tail of the list

        void removeFront();             // remove from head

        void removeBack();              // remove from tail

    protected:
        void add(Node<T> *node, const T& value);       // insert new node after before "node"

        void remove(Node<T> *node);         // remove node "node"
};
