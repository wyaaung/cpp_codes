#include <iostream>
#include <vector>

using namespace std;

void generateSubArrays(vector<int> arr);

void generateSubArrayRecursive(vector<int> arr, int start, int end);

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4};
    cout << "Printing Subarrays Iteratively" << "\n";
    generateSubArrays(arr);
    cout << "\nPrinting Subarrays Recursively" << "\n";
    generateSubArrayRecursive(arr, 0, 0);
    
    return 0;
}

void generateSubArrays(vector<int> arr) {
    // Number of items in vector array.
    int n = arr.size();

    // Starting Element
    for (int a = 0; a < n; a++){
        // Ending Element
        for(int b = a; b < n; b++){
            // Print Subarray between current starting and ending elements
            cout << "[";
            for (int c = a; c <= b; c++){
                cout << arr[c] << " ";
            }
            cout << "]\n";
        }
        
    }
}

void generateSubArrayRecursive(vector<int> arr, int start, int end){
    // Number of items in vector array.
    int n = arr.size();

    // If end index reached the end of the array, return.
    if (end == n){
        return;
    }

    // Increment the end index if start index is greater than end index
    else if (start > end){
        generateSubArrayRecursive(arr, 0, end + 1);
    }

    else{
        // Print the subarray and increase the start index
        cout << "[";
        for (int i = start; i <= end; i++){
            cout << arr[i] << " ";
        }
        cout << "]\n";

        generateSubArrayRecursive(arr, start + 1, end);
    }
}