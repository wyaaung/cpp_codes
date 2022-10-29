#include <iostream>
#include <vector>

#define SIZE 100000

/**
 * Create N empty buckets (or Lists)
 * Insert arr[i] into bucket[n*array[i]]
 * Sort individual buckets using insertion sort.
 * Concatenate all sorted buckets
 */

/*
Distributing the elements of an array into a number of buckets.

Time Complexity: O(n^2) Worst Case
Space Complexity: O(n+k) Worst Case where k is the number of buckets
 */

using namespace std;

void display(vector<float> &arr){
    cout << "[";
    for (auto x: arr){
        cout << x << ", ";
    }
    cout << "]\n";
}

void insertionSort(vector<float> &arr){
    float key; int j;

    for (int i = 1; i < arr.size(); i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void bucketSort(vector<float> &arr){
    // Number of items in arr
    int N = arr.size();

    vector<float> buckets[N];

    // Put arr elements in different buckets
    for (int i = 0; i < N; i++){
        int bucketIndex = N * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < N; i++){
        insertionSort(buckets[i]);
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < buckets[i].size(); j++){
            arr[index++] = buckets[i][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<float> intVector;
    for (int i = 0; i < SIZE; i++){
        intVector.push_back((float) rand()/RAND_MAX);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    clock_t start = clock(); 
    bucketSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
