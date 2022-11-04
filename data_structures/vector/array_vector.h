#include <iostream>
#include <stdexcept>

using namespace std;

struct IndexOutOfBounds : public runtime_error
{
    IndexOutOfBounds(const char* msg) : runtime_error(msg) {}
};

template <typename T>
class ArrayVector {
    private:
        int capacity;
        int n;
        T* array;

    public:
        ArrayVector();

        ~ArrayVector();

        int size() const;

        bool empty() const;

        /* Element at index i */
        T& operator[](int i);

        /* Element at index i */
        T& at(int i) throw(IndexOutOfBounds);

        /* Remove element at index i */
        void erase(int i);

        /* Insert element at index i */
        void insert(int i, const T& value);

        /* Reserve at least N spots */
        /* Allows users to expand the capacity to at least N */
        void reserve(int N);
};
