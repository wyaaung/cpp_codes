#include "intStack.h"

IntegerStack::IntegerStack(int maxSize) {
    this->array = new int[maxSize];
};

int IntegerStack::size(){
    return this->pos;
}

bool IntegerStack::isEmpty() {
    return (this->pos == 0);
}

int IntegerStack::peek(){
    return this->array[this->pos - 1];
}

void IntegerStack::push(int value){
    this->array[this->pos++] = value;
}

int IntegerStack::pop(){
    return this->array[--this->pos];
}

int main(int argc, char const *argv[])
{
    IntegerStack *intStack = new IntegerStack(5);

    intStack->push(1);
    intStack->push(2);
    intStack->push(3);
    intStack->push(4);
    intStack->push(5);

    cout << intStack->pop() << "\n";
    cout << intStack->pop() << "\n";
    cout << intStack->pop() << "\n";

    intStack->push(3);
    intStack->push(4);
    intStack->push(5);

    while(!intStack->isEmpty()){
        cout << intStack->pop() << "  ";
    }

    cout << "\n";

    return 0;
}
