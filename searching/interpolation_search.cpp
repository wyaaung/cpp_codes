#include <iostream>
#include <vector>

#define SIZE 100000

/**
 * A fast alternative to a binary search when the elements are uniformly distributed. This
 * algorithm runs in a time complexity of ~O(log(log(n))).
 * 
 */

using namespace std;

int interpolationSearch(vector<int> &arr, int search){
    int low = 0, high = arr.size() - 1, mid = 0;

    while (arr[low] <= search && arr[high] >= search){
        mid = low + ((search - arr[low]) * (high - low)) / (arr[high] - arr[low]);
        
        if (arr[mid] == search){
            return mid;
        }else if (arr[mid] < search){
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }

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
    int index = interpolationSearch(intVector, searchingValue);
    clock_t end = clock();

    cout << "Value:" <<searchingValue << " is found at index: " << index << ".\n";

    cout << "Searching Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
