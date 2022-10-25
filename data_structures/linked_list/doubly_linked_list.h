#include <iostream>

using namespace std;

template <typename T>
class Node {
    private:
        T value;
        Node<T> *next, *prev;

    public:
        Node(T value);
        Node(T value, Node<T> *&next, Node<T> *&prev);
};

template<class T> void swap(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}
