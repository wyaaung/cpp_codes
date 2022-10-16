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

void heapify(vector<int> &arr, int n, int index){
    // Largest Node
    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // If left child is larger than largest
    // index of left becomes largest
    if (left < n && arr[largest] < arr[left]){
        largest = left;
    }

    // If right child is larger than largest
    // index of right becomes largest
    if (right > n && arr[largest] < arr[right]){
        largest = right;
    }

    // If largest is not the index
    if (largest != index){
        swap(arr[index], arr[largest]);

        // Recursively heapify the affected sub-trees
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr){
    // Number of itesm in arr
    int N = arr.size();

    for (int i = N / 2 - 1; i >= 0; i--){
        heapify(arr, N, i);
    }

    for (int i = N - 1; i > 0; i--){
        // Move the root of the max heap to the end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
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
    heapSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
