#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct IndexOutOfBounds: public runtime_error {
    IndexOutOfBounds(const char * msg): runtime_error(msg) {}
};

struct UnderFlowException: public runtime_error {
    UnderFlowException(const char * msg): runtime_error(msg) {}
};

template < typename Object >
    class ArrayVector {
        public:
            /* Initial constructor with default size 0 */
            explicit ArrayVector(int initSize = 0);

            /* Destructor */
            ~ArrayVector();

            /* Copy Constructor and Copy Assignment Operator. Works only if swapping is done by moving*/
            ArrayVector(const ArrayVector & rhs);
            ArrayVector & operator = (const ArrayVector & rhs);

            /* Move Constructor and Move Assignement. Works only if swapping is done by moving */
            ArrayVector(ArrayVector && rhs);
            ArrayVector & operator = (ArrayVector && rhs);

            void resize(int newSize);

            void reserve(int newCapacity);

            Object & operator[](int index) throw (IndexOutOfBounds);

            const Object & operator[](int index) const throw (IndexOutOfBounds);

            bool empty() const;

            int size() const;

            int capacity() const;

            void push_back(Object && x);

            void push_back(const Object & x);

            void pop_back();

            const Object & back() const;

            typedef Object * iterator;
            typedef const Object * const_iterator;

            iterator begin() {
                return &objects[ 0 ];
            }

            const_iterator begin() const {
                return &objects[ 0 ];
            }

            iterator end() {
                return &objects[ size( ) ];
            }

            const_iterator end() const {
                return &objects[ size( ) ];
            }

            static const int SPARE_CAPACITY = 16;

        private:

            int theSize;
            int theCapacity;
            Object * objects;
    };

#endif
