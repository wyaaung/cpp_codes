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

void bubbleSort(vector<int> &arr){
    //Number of items in the array
    int n = arr.size();

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 0; i < 100; i++){
        intVector.push_back(100 - i);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    bubbleSort(intVector);

    cout << "After Sorting: \n";
    display(intVector);

    return 0;
}
