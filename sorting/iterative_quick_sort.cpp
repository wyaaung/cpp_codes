#include <iostream>
#include <vector>

#define SIZE 10

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
    // Initializing stack
    int stack[arr.size()];

    // Initialize top of the stack
    int top = -1;

    stack[++top] = start;
    stack[++top] = end;

    while (top >= 0){
        end = stack[top--];
        start = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int pivotIndex = partition(arr, start, end);

        if (pivotIndex - 1 > start){
            stack[++top] = start;
            stack[++top] = pivotIndex - 1;
        }

        if (pivotIndex + 1 < end){
            stack[++top] = pivotIndex + 1;
            stack[++top] = end;
        }
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