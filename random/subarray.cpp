#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief Generate the subarray of the given array
 * 
 * In general, for an array of size n, there are n*(n+1) / 2 non empty subarrays
 */

void generateSubArrays(vector<int> arr);

void generateSubArrayRecursive(vector<int> arr, int start, int end);

// Time Complexity of the below algorithm is O(n^3)
void maximumSumofSubArraysOne(vector<int> arr);

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4};
    
    cout << "Printing Subarrays Iteratively" << "\n";
    generateSubArrays(arr);

    cout << "\nPrinting Subarrays Recursively" << "\n";
    generateSubArrayRecursive(arr, 0, 0);
    
    cout << "\nSum of Maximum Subarray (O(n^3))" << "\n";
    maximumSumofSubArraysOne(arr);

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

void maximumSumofSubArraysOne(vector<int> arr){
    // Number of items in vector array.
    int n = arr.size();
    int best = 0;

    // Starting Element
    for (int start = 0; start < n; start++){
        for (int end = start; end < n; end++){
            int sum = 0;
            cout << "Sum of [";
            for (int i = start; i <= end; i++){
                sum += arr[i]; 

                if (i == end){
                    cout << arr[i];
                }
                else{
                    cout << arr[i] << ", ";
                }
            }
            cout << "] = " << sum << "\n";
            best = max(best, sum);
        }
    }

    cout << "Maximum Sum of Subarray = " << best << "\n";
}
