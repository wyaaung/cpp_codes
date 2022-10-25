#include "singly_linked_list.h"

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = NULL;
}

template<typename T>
Node<T>::Node(T value, Node<T> *&next) {
    this->value = value;
    this->next = next;
}
