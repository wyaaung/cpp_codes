#include <iostream>
#include <vector>

#define SIZE 100000

/**
 * similar to binary search where we divide the array into two parts 
 * but in this algorithm, we divide the given array into three parts 
 * and determine which has the key (searched element).
 *
 */

/*
Time Complexity: O(log3n), where n is the size of the array.
Auxiliary Space: O(1)

Same as the binary search. The only difference is that, it reduces the time complexity a bit more.
Its time complexity is O(log n base 3) and that of binary search is O(log n base 2).
*/

using namespace std;

int tenarySearch(vector<int> &arr, int search){
    int low = 0, high = arr.size() - 1, midOne = 0, midTwo = 0;

    while (arr[low] <= search && arr[high] >= search){
        midOne = low + (high - low) / 3;
        midTwo = high - (high - low) / 3;

        if (arr[midOne] == search){
            return midOne;
        }

        if (arr[midTwo] == search){
            return midTwo;
        }

        if (search < arr[midOne]){
            high = midOne - 1;
        }else if (search > arr[midTwo]){
            low = midTwo + 1;
        }else{
            low = midOne + 1;
            high = midTwo - 1;
        }
    }

    // Return -1 when there is no such element in the array.
    return -1;
}

int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 1; i <= SIZE; i++){
        intVector.push_back(i);
    }

    int searchingValue = rand() % SIZE;

    clock_t start = clock(); 
    int index = tenarySearch(intVector, searchingValue);
    clock_t end = clock();

    cout << "Value:" <<searchingValue << " is found at index: " << index << ".\n";

    cout << "Searching Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
