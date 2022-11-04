#include <iostream>

using namespace std;

template <typename T>
class NodeList {
    private:
        struct Node {
            T value;
            Node *prev;
            Node *next;
        };
    public:
        class Iterator {
            private:
                Node *pointer;      // Pointer to the node
                Iterator(Node *u);  // Create from a node

            public:
                /* Reference to the element */
                T& operator*();

                /* Compare Positions */
                bool operator==(const Iterator& p) const;
                bool operator!=(const Iterator& p) const;

                /* Move to next and previous positions */
                Iterator& operator++();     // Pre Increment ++p
                Iterator& operator++(int);  // Post Increment p++
                Iterator& operator--();     // Pre Decrement --p
                Iterator& operator--(int);  // Post Decrement --p
        };

    public:
        NodeList();

        int size() const;

        bool empty() const;

        Iterator begin() const;

        Iterator end() const;

        void insertFront(const T& value);

        void insertBack(const T& value);

        /* Insert element before p */
        void insert(const Iterator& p, const T& value);

        void eraseFront();

        void eraseBack();

        void erase(const Iterator& p);      // Remove p

    private:
        int n;
        Node *header;
        Node *trailer;
};
