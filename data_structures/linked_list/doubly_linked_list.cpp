#include "doubly_linked_list.h"

template <typename T>
Node<T>::Node() {
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename T>
Node<T>::Node(T value) {
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    /* Create Sentinel Nodes */
    this->header = new Node<T>();
    this->tailer = new Node<T>();

    /* Pointing each other*/
    this->header->next = this->tailer;
    this->tailer->prev = this->header;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    /* Remove all but Sentinel Nodes */
    while(!empty()) removeFront();

    delete this->header;
    delete this->tailer;
}

template <typename T>
bool DoublyLinkedList<T>::empty() const {
    return (this->header->next == this->tailer);
}

template <typename T>
const T& DoublyLinkedList<T>::head() const {
    return (this->header->next->value);
}

template <typename T>
const T& DoublyLinkedList<T>::tail() const {
    return (this->tailer->prev->value);
}

template <typename T>
void DoublyLinkedList<T>::add(Node<T> *node, const T& value) {
    Node<T>* newNode = new Node<T>();
    newNode->value = value;

    newNode->next = node;
    newNode->prev = node->prev;
    node->prev->next = newNode;
    node->prev = newNode;
}

template <typename T>
void DoublyLinkedList<T>::addFront(const T& value) {
    /* Add to front of the list */
    add(this->header->next, value);
}

template <typename T>
void DoublyLinkedList<T>::addBack(const T& value) {
    /* Add to back of the list */
    add(this->tailer, value);
}

template <typename T>
void DoublyLinkedList<T>::remove(Node<T> *node) {
    /* Remove Node name "node"*/
    Node<T>* prev = node->prev;
    Node<T>* next = node->next;

    prev->next =  next;
    next->prev = prev;

    delete node;
}

template <typename T>
void DoublyLinkedList<T>::removeFront() {
    remove(this->header->next);
}

template <typename T>
void DoublyLinkedList<T>::removeBack() {
    remove(this->tailer->prev);
}
