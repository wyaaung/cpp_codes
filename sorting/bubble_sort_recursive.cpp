#include <iostream>
#include <vector>

#define SIZE 100000

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

void bubbleSortRecursive(vector<int> &arr, int n){
    if (n <= 1){
        return;
    }

    int count = 0;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.

    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr [i + 1]){
            swap(arr[i], arr[i + 1]);
            count++;
        }
    }

    if (count == 0){
        return;
    }
    
    // Largest element is fixed,
    // recur for remaining array
    bubbleSortRecursive(arr, n - 1);
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
    bubbleSortRecursive(intVector, SIZE);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}

