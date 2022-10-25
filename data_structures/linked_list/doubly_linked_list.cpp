#include "doubly_linked_list.h"

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = NULL;
    this->prev = NULL;
}

template <typename T>
Node<T>::Node(T value, Node<T> *&next, Node<T> *&prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}