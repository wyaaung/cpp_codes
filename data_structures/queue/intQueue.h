#include "queue.h"

class IntegerQueue : public Queue<int> {
    private:
        int *array;
        int capacity, front, end;

    public:
        // maxSize is the maximum number of items
        // that can be in the queue at any given time
        IntegerQueue(int maxSize);

        // push the element on the stack
        void enqueue(int value);

        // return if the stack is empty
        bool isEmpty();

        // return the number of elements in the stack
        int size();

        // Peek the element off the stack without actually removing.
        int peek();

        // return true/false on whether the queue is full
        int isFull();

        // pop the element off the stack
        int poll();
};