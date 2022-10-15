#include <iostream>
#include <vector>

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
    for (int i = 0; i < 10; i++){
        intVector.push_back(10 - i);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    clock_t start = clock(); 
    quickSort(intVector, 0, 9);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}