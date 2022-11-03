#include "singly_linked_list.h"

template <typename T>
Node<T>::Node() {
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() {
    this->header = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (!empty()) {
        removeFront();
    }
}

template <typename T>
bool SinglyLinkedList<T>::empty() const {
    return this->header == nullptr;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const {
    return this->header->value;
}

template <typename T>
void SinglyLinkedList<T>::addFront(const T& value) {
    Node<T> *newNode = new Node<T>(value);

    newNode->next = this->header;
    this->header = newNode;
}

template <typename T>
void SinglyLinkedList<T>::removeFront() {
    Node<T> *oldNode = new Node<T>(value);

    this->header = oldNode->next;
    delete oldNode;
}
