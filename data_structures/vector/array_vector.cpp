#include "array_vector.h"

template < typename Object >
    ArrayVector < Object > ::ArrayVector(int initSize):
    theSize { initSize },
    theCapacity { initSize + SPARE_CAPACITY} {
        objects = new Object[theCapacity];
    }

template < typename Object >
    ArrayVector < Object > ::~ArrayVector() {
        delete[] objects;
    }

template < typename Object >
    ArrayVector < Object > ::ArrayVector(const ArrayVector & rhs):
    theSize { rhs.theSize },
    theCapacity { rhs.theCapacity },
    objects { nullptr} {
        objects = new Object[theCapacity];
        for (int k = 0; k < theSize; ++k) {
            objects[k] = rhs.objects[k];
        }
    }

template < typename Object >
    ArrayVector < Object > & ArrayVector < Object > ::operator = (const ArrayVector & rhs) {
        ArrayVector copy = rhs;
        swap( * this, copy);
        return *this;
    }

template < typename Object >
    /* Move all elements into left hand side array. */
    ArrayVector < Object > ::ArrayVector(ArrayVector && rhs): 
    theSize { rhs.theSize },
    theCapacity { rhs.theCapacity },
    objects { rhs.objects } {
        rhs.objects = nullptr;
        rhs.theSize = 0;
        rhs.theCapacity = 0;
    }

template < typename Object >
    ArrayVector < Object > & ArrayVector < Object > ::operator = (ArrayVector && rhs) {
        swap(theSize, rhs.theSize);
        swap(theCapacity, rhs.theCapacity);
        swap(objects, rhs.objects);

        return *this;
    }

template < typename Object >
    void ArrayVector < Object > ::resize(int newSize) {
        if (newSize > theCapacity) {
            reserve(newSize * 2);
        }

        theSize = newSize;
    }

template < typename Object >
    void ArrayVector < Object > ::reserve(int newCapacity) {
        if (newCapacity < theSize) return;

        Object * newArray = new Object[newCapacity];

        for (int k = 0; k < theSize; ++k) {
            newArray[k] = move(objects[k]);
        }

        theCapacity = newCapacity;

        swap(objects, newArray);
        delete[] newArray;
    }

template < typename Object >
    Object & ArrayVector < Object > ::operator[](int index) throw (IndexOutOfBounds) {
        if ( index < 0 || index >= theSize) {
            throw IndexOutOfBounds("INDEX OUT OF BOUNDS");
        }

        return objects[index];
    }

template < typename Object >
    const Object & ArrayVector < Object > ::operator[](int index) const throw (IndexOutOfBounds) {
        if ( index < 0 || index >= theSize) {
            throw IndexOutOfBounds("INDEX OUT OF BOUNDS");
        }

        return objects[index];
    }

template < typename Object >
    bool ArrayVector < Object > ::empty() const {
        return size() == 0;
    }

template < typename Object >
    int ArrayVector < Object > ::size() const {
        return theSize;
    }

template < typename Object >
    int ArrayVector < Object > ::capacity() const {
        return theCapacity;
    }

template < typename Object >
    void ArrayVector < Object > ::push_back(const Object & x) {
        if (theSize == theCapacity) {
            reserve(2 * theCapacity + 1);
        }

        objects[theSize++] = x;
    }

template < typename Object >
    void ArrayVector < Object > ::push_back(Object && x) {
        if (theSize == theCapacity) {
            reserve(2 * theCapacity + 1);
        }

        objects[theSize++] = move(x);
    }

template < typename Object >
    void ArrayVector < Object > ::pop_back() {
        --theSize;
    }

template < typename Object >
    const Object & ArrayVector < Object > ::back() const {
        return objects[theSize - 1];
    }
