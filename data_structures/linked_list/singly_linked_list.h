#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T value;
        Node<T> *next;

        friend class SinglyLinkedList<T>;

    public:
        Node();
        Node(T value);
};

template<class T> void swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
class SinglyLinkedList {
    private:
        Node<T> *header;

    public:
        SinglyLinkedList();

        ~SinglyLinkedList();
        // is list empty?
        bool empty() const;
        // get front value
        const T& front() const;
        // add from head
        void addFront(const T& value);
        // remove from head
        void removeFront();
};
