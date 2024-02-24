#include<iostream>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }
    else
    {
        return n*factorial(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter the number to find the factorial : ";
    cin>>n;
    if (n==0)
    {
        cout<<"Factorial of the number : 1";
    }
    else{
        cout<<"Factorial of the number : "<<factorial(n);
    }
    return 0;
}


/*
    ****OUTPUT****
    Enter the number to find the factorial : 6
    Factorial of the number : 720

*/