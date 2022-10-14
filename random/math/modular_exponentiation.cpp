#include <iostream>

#define ll long long
#define uint unsigned int

using namespace std;

int power(ll x, uint y, int p);

int main(int argc, char const *argv[])
{
    cout << power(7, 256, 13) << "\n";
    
    return 0;
}

int power(ll x, uint y, int p){
    int result = 1;

    x = x % p; // Update x if it is more than or equal to p

    if (x == 0) return 0;

    while (y > 0){
        
        //  If y is odd, multiply x with result
        if (y & 1){
            result = (result * x) % p;
        }

        y = y >> 1; // y = y / 2
        x = (x*x) % p;
    }
    return result;
}