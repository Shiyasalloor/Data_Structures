#include<iostream>
using namespace std;

void decimalToBinary(int n){
    if (n>0)
    {
        decimalToBinary(n/2);
        cout<<n%2;
    }
}

int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<n<<" Corresponding binary number : ";
    if (n == 0) {
        std::cout << "0";
    } else {
        decimalToBinary(n);
    }
    return 0;
}

/*
    ****OUT PUT****
       
    Enter a number : 8
    8 Corresponding binary number : 1000
   
*/