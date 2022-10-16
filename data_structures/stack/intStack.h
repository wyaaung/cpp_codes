#include "stack.h"

class IntegerStack : public Stack<int> {
    private:
        int *array;
        int capacity = 0;

    public:
        IntegerStack(int maxSize);

        // return the number of elements in the stack
        int size();

        // return if the stack is empty
        bool isEmpty();

        // push the element on the stack
        void push(int value);

        // pop the element off the stack
        int pop();

        // Peek the element off the stack without actually removing.
        int peek();
};
