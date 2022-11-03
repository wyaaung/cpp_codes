#include <iostream>
#include <stdexcept>

using namespace std;

struct DequeEmpty : public runtime_error
{
    DequeEmpty(const char* msg) : runtime_error(msg) {}
};

template <typename T>
class DoublyLinkedList;

template <typename T>
class Node {
    private:
        T value;
        Node<T> *next, *prev;

        // A friend class can access private and protected members of other class 
        // in which it is declared as friend.
        friend class DoublyLinkedList<T>;
    public:
        Node();
        Node(T value);
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

        Node<T> *header = nullptr;
        Node<T> *tailer = nullptr;

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

template <typename T>
class LinkedDeque {
    private:
        DoublyLinkedList<T> *doublyLinkedList;

        int n;
    
    public:
        /* Constructor */
        LinkedDeque();

        /* Destructor */
        ~LinkedDeque();

        int size() const;

        bool empty() const;
        /* First Value*/
        const T& front() const throw(DequeEmpty);

        const T& back() const throw(DequeEmpty);
        /* Insert new node from front*/
        void insertFront(const T& value);

        void insertBack(const T& value);
        /* remove first node*/
        void removeFront() throw(DequeEmpty);

        void removeBack() throw(DequeEmpty);
};
