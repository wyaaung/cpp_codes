#include <iostream>
#include <stdexcept>

using namespace std;

struct UninitializedIterator: public runtime_error {
    UninitializedIterator(const char * msg): runtime_error(msg) {}
};

template < typename Object >
    class DoublyLinkedList {
        private:
            struct Node {
                Object data;
                Node * prev;
                Node * next;

                Node(const Object & d = Object {}, Node * p = nullptr, Node * n = nullptr):
                data { d }, 
                prev { p }, 
                next { n } {}

                Node(Object && d, Node * p = nullptr, Node * n = nullptr):
                data { move(d) },
                prev { p },
                next { n } {}
            };

        public:
            class const_iterator {
                public:

                    const_iterator():
                    current { nullptr } {}

                    const Object & operator * () const throw ( UninitializedIterator ) {
                        if (current == nullptr) {
                            throw UninitializedIterator("Uninitialized Iterator");
                        }
                        return retrieve();
                    }

                    const_iterator & operator++() throw ( UninitializedIterator ) {
                        if (current == nullptr) {
                            throw UninitializedIterator("Uninitialized Iterator");
                        }
                        current = current -> next;
                        return *this;
                    }

                    const_iterator operator++(int) throw ( UninitializedIterator ) {
                        if (current == nullptr) {
                            throw UninitializedIterator("Uninitialized Iterator");
                        }

                        const_iterator old = * this;
                        ++( * this);
                        return old;
                    }

                    bool operator == (const const_iterator & rhs) const {
                        return current == rhs.current;
                    }

                    bool operator != (const const_iterator & rhs) const {
                        return !( * this == rhs);
                    }

                protected:

                    const DoublyLinkedList<Object> *theDoublyLinkedList;

                    Node * current;

                    Object & retrieve() const {
                        return current -> data;
                    }

                    const_iterator(const DoublyLinkedList<Object> & theList, Node * p):
                    theDoublyLinkedList{ &theList },
                    current { p } {}

                    friend class DoublyLinkedList < Object > ;
            };

        class iterator: public const_iterator {
            public: 
                iterator() {}

                Object & operator * () {
                    return const_iterator::retrieve();
                }

                const Object & operator * () const {
                    return const_iterator::operator * ();
                }

                iterator & operator++() {
                    this -> current = this -> current -> next;
                    return *this;
                }

                iterator operator++(int) {
                    iterator old = * this;
                    ++( * this);
                    return old;
                }

            protected:

                iterator(Node * p):
                const_iterator { p } {}

                friend class DoublyLinkedList < Object > ;
        };

        public:

            DoublyLinkedList();

            ~DoublyLinkedList();

            /* Copy Constructor and Copy Assignment Operator. Works only if swapping is done by moving*/
            DoublyLinkedList(const DoublyLinkedList & rhs);
            DoublyLinkedList & operator = (const DoublyLinkedList & rhs);

            /* Move Constructor and Move Assignement. Works only if swapping is done by moving */
            DoublyLinkedList(DoublyLinkedList && rhs);
            DoublyLinkedList & operator = (DoublyLinkedList & rhs);

            iterator begin() {
                return {
                    head -> next
                };
            }

            const_iterator begin() const {
                return {
                    head -> next
                };
            }

            iterator end() {
                return {
                    tail
                };
            }

            const_iterator end() const {
                return {
                    tail
                };
            }

            int size() const;

            bool empty() const;

            void clear();

            Object & front();

            const Object & front() const;

            Object & back();

            const Object & back() const;

            void push_front(const Object & x);

            void push_front(Object && x);

            void push_back(const Object & x);

            void push_back(Object && x);

            void pop_front();

            void pop_back();

            /* Insert x before itr */
            iterator insert(iterator itr,
                const Object & x);

            iterator insert(iterator itr, Object && x);

            iterator erase(iterator itr);

            iterator erase(iterator from, iterator to);

        private:
            int theSize;
            Node * head;
            Node * tail;

            void init();
    };
