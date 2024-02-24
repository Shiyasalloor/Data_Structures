#include<iostream>
using namespace std;

void readArray(int arr[], int size) {
    cout<<"Enter "<<size<<" integer elements: ";
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }
}

void printArray(const int arr[], int size) {
    cout<<"Array elements: ";
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool searchArray(const int arr[], int size, int elem) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

void printMinMax(const int arr[], int size) {
    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout<<"Minimum element: "<<min<<endl;
    cout<<"Maximum element: "<<max<<endl;
}

int main() {
    int option;
    int arr[100];
    int size = 0;
    bool isExit = false;

    while (!isExit) {
        cout<<"\n----- Menu -----"<<endl;
        cout<<"1. Read array"<<endl;
        cout<<"2. Print array"<<endl;
        cout<<"3. Search element"<<endl;
        cout<<"4. Print min and max"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your option: ";
        cin>>option;

        switch (option) {
            case 1: {
                cout<<"Enter the size of the array (<= 100): ";
                cin>>size;
                if (size <= 0 || size > 100) {
                    cout<<"Invalid size. Please try again."<<endl;
                    continue;
                }
                readArray(arr, size);
                break;
            }
            case 2: {
                if (size == 0) {
                    cout<<"Array is empty. Please read the array first."<<endl;
                } else {
                    printArray(arr, size);
                }
                break;
            }
            case 3: {
                if (size == 0) {
                    cout<<"Array is empty. Please read the array first."<<endl;
                } else {
                    int elem;
                    cout<<"Enter the element to search: ";
                    cin>>elem;
                    if (searchArray(arr, size, elem)) {
                        cout<<"The element is found."<<endl;
                    } else {
                        cout<<"Sorry,there is no such element."<<endl;
                    }
                }
                break;
            }
            case 4: {
                if (size == 0) {
                    cout<<"Array is empty. Please read the array first."<<endl;
                } else {
                    printMinMax(arr, size);
                }
                break;
            }
            case 5: {
                cout<<"Exited successfully";
                return 0;
            }

            default :{
                cout<<"Invalid option";
                break;
            }
        }
    }
    return 0;
}

/*
    ****OUTPUT****

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 1
    Enter the size of the array (<= 100): 5
    Enter 5 integer elements: 6
    7
    8
    9
    4

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 2
    Array elements: 6 7 8 9 4

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 3
    Enter the element to search: 6
    The element is found.

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 3
    Enter the element to search: 10
    Sorry,there is no such element.

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 4
    Minimum element: 4
    Maximum element: 9

    ----- Menu -----
    1. Read array
    2. Print array
    3. Search element
    4. Print min and max
    5. Exit
    Enter your option: 5
    Exited successfully

*/