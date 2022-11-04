#include "array_vector.h"

template <typename T>
ArrayVector<T>::ArrayVector() {
    this->capacity = 0;
    this->n = 0;
    this->array = NULL;
}

template <typename T>
int ArrayVector<T>::size() const {
    return this->n;
}

template <typename T>
bool ArrayVector<T>::empty() const {
    return (this->n == 0);
}

template <typename T>
T& ArrayVector<T>::operator[](int i) {
    return this->array[i];
}

template <typename T>
T& ArrayVector<T>::at(int i) throw(IndexOutOfBounds){
    if (i < 0 || i >= this->n)
        throw IndexOutOfBounds("Illegal Index In Function at()");
    
    return this->array[i];
}

template <typename T>
void ArrayVector<T>::erase(int i) {     // O(n)
    /* Shifts elements at index i*/
    for (int j = i + 1; j < this->n; j++) {
        this->array[j - 1] = this->array[j];
    }

    this->n--;
}

template <typename T>
void ArrayVector<T>::reserve(int N) {
    /* Just one array replacement requires O(n) */
    /* Already Big Enough*/
    if (this->capacity >= N) return;

    T* tempArray = new T[N];

    for (int j = 0; j < this->n; j++) {
        tempArray[j] = this->array[j];
    }

    /* Discard the old array */
    if (this->array != NULL) delete []this->array;

    this->array = tempArray;

    this->capacity = N;
}
template <typename T>
void ArrayVector<T>::insert(int i, const T& value) {        // O(n)
    /* Double the array size if overflow */
    if (this->n >= this->capacity) {
        reserve( max(1, 2 * this->capacity));
    }

    /* Shifts Elements Up */
    for (int j = this->n - 1; j >= i; j--) {
        this->array[j + 1] = this->array[j];
    }

    this->array[i] = value;
    this->n++;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
