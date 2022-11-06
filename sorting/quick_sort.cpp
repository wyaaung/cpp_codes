#include <iostream>
#include <vector>

/*
Time Complexity: O(n*log(n))
Auxiliary Space: O(n)

1. Partition process is the same in both recursive and iterative. The same techniques to choose optimal pivot can also be applied to the iterative version.
2. To reduce the stack size, first push the indexes of smaller half.
3. Use insertion sort when the size reduces below an experimentally calculated threshold.
*/
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

int partition(vector<int> &arr, int start, int end){
    int pivot = arr[end];

    // Index of smaller element and
    // indicates the right position
    // of pivot found so far
    int swapMarker = (start - 1);

    for (int currentIndex = start; currentIndex < end; currentIndex++){
        if(arr[currentIndex] < pivot){
            //Increment index of smaller element
            swapMarker++;
            swap(&arr[swapMarker], &arr[currentIndex]);
        }
    }

    swap(&arr[swapMarker+1], &arr[end]);
    return swapMarker+1;
}

void quickSort(vector<int> &arr, int start, int end){
    if (start < end){
        int pivotIndex = partition(arr, start, end);

        // Separately sort elements before
        // partition and after partition

        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
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
    quickSort(intVector, 0, SIZE - 1);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
