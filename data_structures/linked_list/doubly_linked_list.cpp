#include "doubly_linked_list.h"

template < typename Object >
    DoublyLinkedList < Object > ::DoublyLinkedList() {
        init();
    }

template < typename Object >
    DoublyLinkedList < Object > ::~DoublyLinkedList() {
        clear();
        delete head;
        delete tail;
    }

template < typename Object >
    DoublyLinkedList < Object > ::DoublyLinkedList(const DoublyLinkedList & rhs) {
        init();
        for (auto & x: rhs) {
            push_back(x);
        }
    }

template < typename Object >
    DoublyLinkedList < Object > & DoublyLinkedList < Object > ::operator = (const DoublyLinkedList & rhs) {
        DoublyLinkedList copy = rhs;
        swap( * this, copy);
        return *this;
    }

template < typename Object >
    DoublyLinkedList < Object > ::DoublyLinkedList(DoublyLinkedList && rhs):
    theSize { rhs.theSize },
    head { rhs.head },
    tail { rhs.tail } {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

template < typename Object >
    DoublyLinkedList < Object > & DoublyLinkedList < Object > ::operator = (DoublyLinkedList & rhs) {
        swap(theSize, rhs.theSize);
        swap(head, rhs.head);
        swap(tail, rhs.tail);

        return *this;
    }

template < typename Object >
    int DoublyLinkedList < Object > ::size() const {
        return theSize;
    }

template < typename Object >
    bool DoublyLinkedList < Object > ::empty() const {
        return size() == 0;
    }

template < typename Object >
    void DoublyLinkedList < Object > ::clear() {
        while (!empty()) {
            pop_front();
        }
    }

template < typename Object >
    Object & DoublyLinkedList < Object > ::front() {
        return *begin();
    }

template < typename Object >
    const Object & DoublyLinkedList < Object > ::front() const {
        return *begin();
    }

template < typename Object >
    Object & DoublyLinkedList < Object > ::back() {
        return *--end();
    }

template < typename Object >
    const Object & DoublyLinkedList < Object > ::back() const {
        return *--end();
    }

template < typename Object >
    void DoublyLinkedList < Object > ::push_front(const Object & x) {
        insert(begin(), x);
    }

template < typename Object >
    void DoublyLinkedList < Object > ::push_front(Object && x) {
        insert(begin(), move(x));
    }

template < typename Object >
    void DoublyLinkedList < Object > ::push_back(const Object & x) {
        insert(end(), x);
    }

template < typename Object >
    void DoublyLinkedList < Object > ::push_back(Object && x) {
        insert(end(), move(x));
    }

template < typename Object >
    void DoublyLinkedList < Object > ::pop_front() {
        erase(begin());
    }

/*  note that erase(--end()) creates a temporary iterator corresponding
to the endmarker, retreats the temporary iterator, and uses that iterator to erase */
template < typename Object >
    void DoublyLinkedList < Object > ::pop_back() {
        erase(--end());
    }

template < typename Object >
    void DoublyLinkedList < Object > ::init() {
        theSize = 0;
        head = new Node;
        tail = new Node;
        head -> next = tail;
        tail -> prev = head;
    }

template < typename Object >
    typename DoublyLinkedList < Object > ::iterator DoublyLinkedList < Object > ::insert(iterator itr,
        const Object & x) {
        Node * p = itr.current;

        theSize++;

        return { p -> prev = p -> prev -> next = new Node { x, p -> prev, p } };
    }

template < typename Object >
    typename DoublyLinkedList < Object > ::iterator DoublyLinkedList < Object > ::insert(iterator itr,
        Object && x) {
        Node * p = itr.current;

        theSize++;

        return { p -> prev = p -> prev -> next = new Node { move(x), p -> prev, p } };
    }

template < typename Object >
    typename DoublyLinkedList < Object > ::iterator DoublyLinkedList < Object > ::erase(iterator itr) {
        Node * p = itr.current;

        iterator retVal {
            p -> next
        };
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        delete p;
        theSize--;

        return retVal;
    }

template < typename Object >
    typename DoublyLinkedList < Object > ::iterator DoublyLinkedList < Object > ::erase(iterator from, iterator to) {
        for (iterator itr = from; itr != to;) {
            itr = erase(itr);
        }

        return to;
    }
