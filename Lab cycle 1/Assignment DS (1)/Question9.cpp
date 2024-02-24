#include<iostream>
#include<algorithm>
using namespace std;

void mergeArrays(const int arr1[], const int arr2[], int size, int result[]) {
    int i = 0;
    int j = 0;
    int k = 0; 

    while (i < size && j < size) {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main(){
    int size;
    cout << "Enter the size of the arrays: ";
    cin >> size;

    int arr1[size];
    cout << "Enter elements for array 1: ";
    for (int i = 0; i < size; i++){
        cin >> arr1[i];
    }

    int arr2[size];
    cout << "Enter the elements for array 2: ";
    for (int i = 0; i < size; i++){
        cin >> arr2[i];
    }

    int nsize = size + size;
    int arr3[nsize];
    mergeArrays(arr1, arr2, size, arr3);

    cout << "Merged array (sorted in reverse order): ";
    for (int i = nsize - 1; i >= 0; i--){
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
    ****OUTPUT****

    Enter the size of the arrays: 5
    Enter elements for array 1: 2
    5
    9
    15
    20
    Enter the elements for array 2: 3
    4
    8
    13
    25
    Merged array (sorted in reverse order): 25 20 15 13 9 8 5 4 3 2
    
*/