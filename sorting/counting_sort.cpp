/**
 * @details Counting sort that sorts an array in O(n) time,
 * assuming that every element in the array is positive integer.
 * It keeps a book-keeping array, whose indices are elements of the original array.
 * The algo iterates through the original array and calculates how many times each element appears in the array.
 * 
 */
#include <iostream>
#include <vector>
#include <cstdlib>


#define uint unsigned int

using namespace std;

void display(vector<int> &arr){
    cout << "[";

    for (auto x: arr){
        cout << x << ", ";
    }
    
    cout << "]\n";
}

void countSort(vector<int> &arr){
    // Number of items in the array arr
    int n = arr.size();

    // The maximum element in the array arr
    int max = *max_element(arr.begin(), arr.end());

    // Output array that will have sorted arr
    vector<int> output(arr.size(), 0);

    // Count vector as 0.
    vector<int> count(max + 1, 0);

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    int index = 0;
    for (int j = 0; j < count.size(); j++){
        while(count[j] > 0){
            arr[index++] = j;
            count[j]--;
        }
    }

}

int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 0; i < 100000; i++){
        intVector.push_back(rand() % 1000);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    clock_t start = clock(); 
    countSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}