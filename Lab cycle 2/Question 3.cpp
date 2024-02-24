#include<iostream>
#include<string>
using namespace std;

void selectionSort(string arr[],int n){
    for(int i=0 ;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        string temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    string arr[n];
    
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0 ; i<n;i++){
        cin>>arr[i];
    }
    
    selectionSort(arr,n);
    
    cout<<"The sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" , ";
    }
    return 0;
}