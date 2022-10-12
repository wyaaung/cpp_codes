#include <iostream>

#define unsigned int uint

using namespace std;

void printN(int n);
uint fact (uint n);
uint factTRWrapper(uint n);
uint fibonacci (uint n);

int main(int argc, char const *argv[]){
    printN(10);
    
    cout << fact(10) << "\n";
    
    cout << factTRWrapper(10) << "\n";

    cout << fibonacci(10) << "\n";

    return 0;
}

void printN(int n){
    if (n < 0){
        cout << "\n";
        return;
    }
    cout << n << " ";
    // The last statement is recursive call.
    // Example of Tail Recursion
    printN(n-1);
}

// Non-Tail Recursion
uint fact (uint n){
    if (n <= 0){
        return 1;
    }

    return n * fact(n - 1);
}

// To use one more argument to store the factorial value 
// in the second argument.
// Tail Recursion
uint factTR(uint n, uint a){
    if (n <= 0){
        return a;
    }

    return factTR(n - 1, n * a);
}

//Wrapper Function
uint factTRWrapper(uint n){return factTR(n, 1);}

uint fibonacci (uint n){
    if (n == 0){
        return 0;
    }

    if (n == 1 || n == 2){
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}