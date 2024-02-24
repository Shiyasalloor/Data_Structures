#include<iostream>
#include<cstring>
using namespace std;

int printReverse(string & str,int index){
    if (index<0)
    {
        return 0;
    }
    else{
        cout<<str[index];
        printReverse(str,index-1);
    }
    
}

int main(){
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    int length=str.length();
    cout<<"The reversed string : ";
    printReverse(str,(length-1));
    return 0;
}

/*
    ****OUTPUT****

    Enter the string : SHIYASALLOOR
    The reversed string : ROOLLASAYIHS

*/