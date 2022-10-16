#include "intQueue.h"

IntegerQueue::IntegerQueue(int maxSize){
    this->front = this->end = this->capacity = 0;
    this->array = new int[maxSize];
}

void IntegerQueue::enqueue(int value){
    if (this->isFull()){
        cout << "Queue too small!" << "\n";
        return;
    }

    this->array[end++] = value;
    this->capacity++;
}

bool IntegerQueue::isEmpty(){
    return (this->capacity == 0);
}

int IntegerQueue::size(){
    return this->capacity;
}

int IntegerQueue::peek(){
    if(this->isEmpty()){
        cout << "Queue is empty" << "\n";
        return;
    }


}
