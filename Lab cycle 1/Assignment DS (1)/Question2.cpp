#include<iostream>
using namespace std;

int sum(int n){
    if(n<10){
        return n;
    }
    else{
        return (n%10) + sum(n/10);
    }
}

int main(){
    int n;
    cout<<"Enter a number to find it's digits sum : ";
    cin>>n;
    cout<<"The sum of the digits of the entered number : "<<sum(n);
    return 0;
}


/*
    ****OUTPUT****

    Enter a number to find it's digits sum : 5698
    The sum of the digits of the entered number : 28

*/