#include "int_stack.h"

IntegerStack::IntegerStack(int maxSize) {
    this -> array = new int[maxSize];
};

IntegerStack::~IntegerStack() {
    delete this -> array;
}

int IntegerStack::size() {
    return this -> count;
}

bool IntegerStack::isEmpty() {
    return (this -> count == 0);
}

int IntegerStack::peek() {
    return this -> array[this -> count - 1];
}

void IntegerStack::push(int value) {
    this -> array[this -> count++] = value;
}

int IntegerStack::pop() {
    return this -> array[--this -> count];
}

int main(int argc, char
    const * argv[]) {
    IntegerStack * intStack = new IntegerStack(5);

    intStack -> push(1);
    intStack -> push(2);
    intStack -> push(3);
    intStack -> push(4);
    intStack -> push(5);

    cout << intStack -> pop() << "\n";
    cout << intStack -> pop() << "\n";
    cout << intStack -> pop() << "\n";

    intStack -> push(3);
    intStack -> push(4);
    intStack -> push(5);

    while (!intStack -> isEmpty()) {
        cout << intStack -> pop() << "  ";
    }

    cout << "\n";

    delete intStack;

    return 0;
}
