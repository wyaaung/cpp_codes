#include "factorial.h"

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