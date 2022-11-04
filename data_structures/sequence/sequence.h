#include <iostream>

#include <stdexcept>

using namespace std;

struct IndexOutOfBounds: public runtime_error {
    IndexOutOfBounds(const char * msg): runtime_error(msg) {}
};

struct PositionOutOfBounds: public runtime_error {
    PositionOutOfBounds(const char * msg): runtime_error(msg) {}
};

template < typename T >
    class NodeList {
        private:
            struct Node {
                T value;
                Node * prev;
                Node * next;
            };
        public:
            class Iterator {
                private:
                    Node * pointer; // Pointer to the node
                Iterator(Node * u); // Create from a node

                public:
                    /* Reference to the element */
                    T & operator * ();

                /* Compare Positions */
                bool operator == (const Iterator & p) const;
                bool operator != (const Iterator & p) const;

                /* Move to next and previous positions */
                Iterator & operator++(); // Pre Increment ++p
                Iterator & operator++(int); // Post Increment p++
                Iterator & operator--(); // Pre Decrement --p
                Iterator & operator--(int); // Post Decrement --p
            };

        public:
            NodeList();

        int size() const;

        bool empty() const;

        Iterator begin() const;

        Iterator end() const;

        void insertFront(const T & value);

        void insertBack(const T & value);

        /* Insert element before p */
        void insert(const Iterator & p,
            const T & value);

        void eraseFront();

        void eraseBack();

        void erase(const Iterator & p); // Remove p

        private:
            int n;

        Node * header;

        Node * trailer;
    };

/* 
 * NodeSequence class inherits from NodeList
 * ADT that supports all functions of list ADT, but also
 * provides functions for accessing elements by their index */

template < typename T >
    class NodeSequence: public NodeList < T > {
        public: typename NodeList < T > ::Iterator atIndex(int i) const
        throw (IndexOutOfBounds); // Get position from index

        int indexOf(const typename NodeList < T > ::Iterator & p) const
        throw (PositionOutOfBounds); // Get index from position
    };
