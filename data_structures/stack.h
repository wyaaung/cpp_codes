#include <iostream>

using namespace std;

template <typename T>
class Stack {
    public:
        // return the number of elements in the stack
        virtual int size() = 0;

        // return if the stack is empty
        virtual bool isEmpty() = 0;

        // push the element on the stack
        virtual void push(T element) = 0;

        // pop the element off the stack
        virtual T pop() = 0;

        // Peek the element off the stack without actually removing.
        virtual T peek() = 0;
};
