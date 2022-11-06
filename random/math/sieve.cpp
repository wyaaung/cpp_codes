#include <iostream>

#define SIZE 100000

using namespace std;

void sieveOfEratosthenes(int n) {
    bool prime[n + 1];

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++){
        if (prime[p] == true){
            for (int i = p * p; i <= n; i += p){
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++){
        if (prime[p]){
            cout << p << " ";
        }
    }

    cout << "\n";
}

int main(){
    sieveOfEratosthenes(SIZE);
}