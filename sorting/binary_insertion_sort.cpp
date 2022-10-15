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

// A binary search based function to find the position
// where item should be inserted in arr[low..high]
int binarySearch(vector<int> &arr, int search, int start, int end){
    while (start <= end){
        int mid = start + (end - start) / 2;

        if (search == arr[mid]){
            return mid + 1;
        }else if (search > arr[mid]){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return start;
}

void binaryInsertionSort(vector<int> &arr){
    int key, j, location;

    for (int i = 1; i < arr.size(); i++){
        key = arr[i];
        j = i - 1;

        // find location where selected should be inseretd
        location = binarySearch(arr, key, 0, j);

        while (j >= location){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[location] = key;
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
    binaryInsertionSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
