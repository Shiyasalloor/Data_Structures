#include<iostream>
using namespace std;

int SecondLargest(int arr[],int size){
    int largest=arr[0];
    int secondLargest=INT8_MIN;

    for(int i=1;i<size;i++){
        if (arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if (arr[i]<largest && arr[i]>secondLargest){
            secondLargest=arr[i];
        }
    }
    return secondLargest;
}

int KthLargest(int arr[],int size,int k){
    if (k<=0 || k>size)
    {
        cout<<"Entered k value is not possible"<<endl;
        return INT8_MIN;
    }
    for (int j = 0; j < k; j++) {
        int maxIndex = 0;
        for (int i = 1; i < size; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        if (j == k - 1) {
            return arr[maxIndex];
        }
        arr[maxIndex] = INT8_MIN;
    }

    return INT8_MIN;
}

int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;
    int arr[size];
    
    cout<<"Enter the Elements for the array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int secondLargest=SecondLargest(arr, size);
    if(secondLargest == INT8_MIN){
        cout<<"There is no second largest element."<<endl;
    } 
    else{
        cout<<"The second largest element is: "<<secondLargest<<endl;
    }

    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    int kthLargest=KthLargest(arr, size, k);
    if (kthLargest == INT8_MIN) {
        cout<<"There is no k-th largest element."<<endl;
    } else {
        cout<<"The "<<k<<"-th largest element is: "<<kthLargest<<endl;
    }

    return 0;
}

/*
    ****OUTPUT****

    Enter the size of the array : 5
    Enter the Elements for the array : 5
    8
    4
    10
    24
    The second largest element is: 10
    Enter the value of k: 3
    The 3-th largest element is: 8

*/