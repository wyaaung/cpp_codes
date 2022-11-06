#include "queue.h"

class IntegerQueue: public Queue < int > {
    private: int * array;
    int capacity,
    front,
    end,
    count;

    public:
        // maxSize is the maximum number of items
        // that can be in the queue at any given time
        IntegerQueue(int maxSize);

    ~IntegerQueue();

    // Add the element on the queue
    void enqueue(int value);

    // return if the queue is empty
    bool isEmpty();

    // return the number of elements in the queue
    int size();

    // Peek the element off the queue without actually removing.
    int peek();

    // return true/false on whether the queue is full
    int isFull();

    // pop the element off the queue
    int dequeue();
};