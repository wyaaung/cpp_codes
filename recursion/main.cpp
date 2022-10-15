#include <iostream>
#include "fibonacci.h"
#include "factorial.h"
#include "copystring.h"

using namespace std;

void printN(int n);

int main(int argc, char const *argv[]){
    printN(10);
    
    cout << fact(10) << "\n";
    
    cout << factTRWrapper(10) << "\n";

    cout << fibonacci(10) << "\n";

    char s1[100] = "Hello, World!";
    char s2[100];

    myCopy(s1, s2, 0);

    cout << s2 << "\n";

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
