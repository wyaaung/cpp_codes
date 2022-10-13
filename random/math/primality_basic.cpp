#include <iostream>
#include <vector>

using namespace std;

// 2 divides (6k + 0), (6k + 2), and (6k + 4) and 3 divides (6k + 3)
// Time Complexity: √n
bool isPrimeSchoolMethod(int n);

int main(int argc, char const *argv[])
{
    isPrimeSchoolMethod(11) ? cout << "11 is prime\n" : cout << "11 is not prime\n";
    isPrimeSchoolMethod(15) ? cout << "15 is prime\n" : cout << "15 is not prime\n";

    return 0;
}

// All primes greater than 3 are of the form 6k ± 1 where k is a positive integer
bool isPrimeSchoolMethod(int n){
    if (n == 2 || n == 3){
        return true;
    }

    if (n <= 1 || n % 2 == 0 || n % 3 == 0){
        return false;
    }

    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
