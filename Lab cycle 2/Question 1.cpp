#include <iostream>
using namespace std;

void bubbleSort(double arr[] ,int size) {
    int n = size;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin >> n;

    double inputNumbers[n];
    for (int i = 0; i < n; i++) {
        cin >> inputNumbers[i];
    }

    bubbleSort(inputNumbers,n);
    
    cout<<"The sorted array : \n";
    
    for (int i=0;i<n;i++) {
        cout << inputNumbers[i] << " ";
    }

    return 0;
}
