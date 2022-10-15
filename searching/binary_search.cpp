#include <iostream>
#include <vector>

#define SIZE 100000

using namespace std;

// Returns an index in an array of the searching value
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
    
    return -1;
}


int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 1; i <= SIZE; i++){
        intVector.push_back(i);
    }

    int searchingValue = rand() % 10000;
    int index = binarySearchIterative(intVector, searchingValue);

    cout << searchingValue << " is found at index: " << index << ".\n";

    return 0;
}
