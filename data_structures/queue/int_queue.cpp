#include "int_queue.h"

// maxSize is the maximum number of items
// that can be in the queue at any given time
IntegerQueue::IntegerQueue(int maxSize){
    this->front = this->end = this->count = 0;
    this->capacity = maxSize;
    this->array = new int[maxSize];
}

IntegerQueue::~IntegerQueue(){
    delete[] this->array;
}

// Add an element to the queue
void IntegerQueue::enqueue(int value){
    if (this->isFull()){
        cout << "Queue Overflow" << "\n";
        return;
    }

    this->array[this->end++] = value;
    this->end = this->end % this->capacity;
    this->count++;
}

// return if the queue is empty
bool IntegerQueue::isEmpty(){
    return (this->count == 0);
}

// return the number of elements in the queue
int IntegerQueue::size(){
    return this->capacity;
}

// Peek the element off the queue without actually removing.
int IntegerQueue::peek(){
    if(this->isEmpty()){
        cout << "Queue is empty" << "\n";
        exit(EXIT_FAILURE);
    }

    return this->array[this->front];
}

// return true/false on whether the queue is full
int IntegerQueue::isFull(){
    return (this->count == this->capacity);
}

// pop the element off the queue
int IntegerQueue::dequeue(){
    if (this->isEmpty()){
        cout << "Queue is Empty" << "\n";
        exit(EXIT_FAILURE);
    }

    this->front = this->front % this->capacity;
    this->count--;

    return this->array[front++];
}

int main(int argc, char const *argv[])
{
    IntegerQueue *q = new IntegerQueue(5);

    for (int i = 1; i <= 5; i++){
        q->enqueue(i);
    }

    for (int i = 1; i <= 4; i++){
        cout << q->dequeue() << "  ";
    }

    cout << "\nThe Queue is " << 
    (q->isEmpty() ? "empty\n" : "not empty\n");

    for (int i = 1; i <= 3; i++){
        q->enqueue(i);
    }

    for (int i = 1; i <= 4; i++){
        cout << q->dequeue() << "  ";
    }

    cout << "\nThe Queue is " << 
    (q->isEmpty() ? "empty\n" : "not empty\n");

    delete q;

    return 0;
}
