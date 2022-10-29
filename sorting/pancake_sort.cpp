#include <iostream>
#include <vector>

/*
Pancake sort is a sorting algorithm in which the only allowed operation is to "flip" one end of the list.
In-place sorting. Unstable.

Time Complexity: O(n^2), Total O(n) flip operations are performed in above code
Auxiliary Space: O(1)
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

/* Reverses arr[0..i] to arr[i..0] */
void flip(vector<int> &arr, int i){
    int temp, start = 0;

    while (start < i){
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;

        start++;
        i--;
    }
}

int indexOfMax(vector<int> &arr, int currentSize){
    int indexOfMax = -1;
    for (int i = 0; i < currentSize; i++){
        if (arr[i] > arr[indexOfMax]){
            indexOfMax = i;
        }
    }
    return indexOfMax;
}

void pancakeSort(vector<int> &arr){
    // Number of items in arr
    int N = arr.size();

    for (int currentSize = N; currentSize > 1; currentSize--){

        int iMax = indexOfMax(arr, currentSize);

        if (iMax != currentSize - 1) {
            flip(arr, iMax);

            flip(arr, currentSize - 1);
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
    pancakeSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
