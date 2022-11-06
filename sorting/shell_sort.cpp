#include <iostream>
#include <vector>

#define SIZE 100000

/**
 * Generalized version of Insertion Sort.
 * Sorts elements that are far apart from each other 
 * and successively reduces the interval between the elements to be sorted.
 * 
 * Time Complexity: O(n^2) (Worst Case Complexity), O(n logn) (Best Case Complexity)
 */

using namespace std;

void display(vector<int> &arr){
    cout << "[";
    for (auto x: arr){
        cout << x << ", ";
    }
    cout << "]\n";
}

void shellSort(vector<int> &arr){
    // Number of items in arr
    int N = arr.size();

    // Sorting elements at interval of each N/2, N/4, N/8,.....
    for (int interval = N/2; interval > 0; interval/=2){
        for (int i = interval; i < N; i++){
            int key = arr[i], j = i;

            while(j >= interval && arr[j - interval] > key){
                arr[j] = arr[j - interval];
                j -= interval;
            }
            arr[j] = key;
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
    shellSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}