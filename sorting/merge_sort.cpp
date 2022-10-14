#include <iostream>
#include <vector>

#define uint unsigned int

using namespace std;

void display(vector<int> &arr){
    cout << "[";

    for (auto x: arr){
        cout << x << ", ";
    }
    
    cout << "]\n";
}

void mergeSort(vector<int> &arr){
    if (arr.size() > 1){

        int mid = arr.size() / 2;
        vector<int> leftArray(arr.begin(), arr.begin() + mid);
        vector<int> rightArray(arr.begin() + mid, arr.end());

        mergeSort(leftArray);
        mergeSort(rightArray);

        // leftArray index, rightArray index, mergedArray index;
        uint i = 0, j = 0, k = 0;

        while(i < leftArray.size() && j < rightArray.size()){
            if (leftArray[i] <= rightArray[j]){
                arr[k] = leftArray[i];
                i++;
            }else{
                arr[k] = rightArray[j];
                j++;
            }
            k++;
        }

        while (i < leftArray.size()){
            arr[k] = leftArray[i];
            i++;
            k++;
        }

        while (j < rightArray.size()){
            arr[k] = rightArray[j];
            j++;
            k++;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> intVector;
    for (int i = 0; i < 100000; i++){
        intVector.push_back(100000 - i);
    }
    cout << "Before Sorting: \n";
    display(intVector);

    clock_t start = clock(); 
    mergeSort(intVector);
    clock_t end = clock();

    cout << "After Sorting: \n";
    display(intVector);

    cout << "Sorting Time: " << ((float)(end - start) / CLOCKS_PER_SEC) << "\n";

    return 0;
}
