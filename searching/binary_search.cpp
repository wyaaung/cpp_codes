#include <iostream>
#include <vector>

#define SIZE 100000

using namespace std;

// Returns an index in an array of the searching value, otherwise -1.
int binarySearchIterative(vector<int> &arr, int search){
    int low = 0, high = arr.size() - 1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        // cout << mid << "\n";

        if (search == arr[mid]){
            return mid;
        } else if (search > arr[mid]){
            low = mid + 1;
        } else{
            high = mid + 1;
        }
    }
    
    // Return -1 when there is no such element in the array.
    return -1;
}

// Returns an index in an array of the searching value, otherwise -1.
int binarySearchRecursive(vector<int> &arr, int search, int start, int end){
    if (end >= 1){
        int mid = start + (end - start) / 2;

        if (search == arr[mid]){
            return mid;
        }

        // If the searching element is smaller than mid, it can only be existed in right side of the array
        if (search > arr[mid]){
            return binarySearchRecursive(arr, search, mid + 1, end);
        }

        // Else the searching element exists in right side of the array
        return binarySearchRecursive(arr, search, start, mid - 1);
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
    int index = binarySearchIterative(intVector, searchingValue);
    clock_t end = clock();

    cout << "Value:" <<searchingValue << " is found at index: " << index << ".\n";

    cout << "Searching Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
