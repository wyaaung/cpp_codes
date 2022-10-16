#include <iostream>

using namespace std;

template <typename T>
class Queue{
    public:
        // Add an element to the queue
        virtual void enqueue(T element) = 0;
        
        // return true/false on whether the queue is empty
        virtual bool isEmpty() = 0;

        // return the number of elements in the queue
        virtual int size() = 0;

        // Peek the element off the queue without actually removing.
        virtual T peek() = 0;
        
        // return true/false on whether the queue is full
        virtual int isFull() = 0;

        // return the element at the head of the queue 
        virtual int dequeue() = 0;
};
