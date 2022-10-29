#include <iostream>
#include <vector>

#define SIZE 100000

/**
 * The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
 *  from the unsorted part and putting it at the beginning. 
 * 
 * The algorithm maintains the subarray which already sorted, and
 * the remaining subarray was unsorted.
 *
 */

/*
Time Complexity: O(n^2)
Space Complexity: O(1)

In place sorting algorithm.
Selection sort is noted for its simplicity and has performance advantages over more complicated algorithms in certain situations,
particularly where auxiliary memory is limited.
*/

using namespace std;

void display(vector<int> &arr){
    cout << "[";
    for (auto x: arr){
        cout << x << ", ";
    }
    cout << "]\n";
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(vector<int> &arr){
    // Number of items in an array
    int n = arr.size();

    if (n <= 1){
        return;
    }

    int swapIndex;
    
    for (int i = 0; i < n; i++){
        swapIndex = i;
        
        for (int j = i + 1; j < n; j++){
            if (arr[j] < arr[swapIndex]){
                swapIndex = j;
            }
        }
        swap(arr[i], arr[swapIndex]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 0; i < SIZE; i++){
        intVector.push_back(SIZE - i);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    clock_t start = clock(); 
    selectionSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
