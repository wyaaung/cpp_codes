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


void insertionSortRecursive(vector<int> &arr, int end){
    if (end <= 1){
        return;
    }

    // Sort first n - 1 elements
    insertionSortRecursive(arr, end - 1);

    // Insert last element at its correct position in sorted array
    int key = arr[end - 1];
    int j = end - 2;

    // Move elements of arr[0..i-1],  
    // that are greater than key, to one 
    // position ahead of their 
    // current position
    while(j >= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
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
    insertionSortRecursive(intVector, intVector.size());
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
