#include <iostream>

#define uint unsigned int
using namespace std;

// Calculating number ^ pow
uint power(int number, int pow){
    if (pow == 0){
        return 1;
    }

    uint y = 0;

    if (pow % 2 == 1){
        y = power(number, (pow - 1) / 2);
        return number * y * y;
    } else {
        y = power(number, pow / 2);
        return y * y;
    }
}

int main(int argc, char const *argv[])
{
    cout << power(13, 7) <<"\n";

    return 0;
}
