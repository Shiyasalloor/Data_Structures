#include <iostream>
using namespace std;

void readMatrix(int** matrix, int rows, int columns){
    cout<<"Enter elements of the matrix:"<<endl;
    for(int i=0;i<rows;i++){
        matrix[i]=new int[columns];
        for(int j=0;j<columns;j++){
            cin>>matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int columns){
    cout<<"Matrix:"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int RowSum(int* row, int columns){
    int sum=0;
    for(int j=0;j<columns;j++){
        sum+=row[j];
    }
    return sum;
}

int ColumnSum(int** matrix, int rows, int column){
    int sum=0;
    for(int i=0;i<rows;i++){
        sum+=matrix[i][column];
    }
    return sum;
}

void largestSum(int** matrix, int rows, int columns){
    int largestRowSum=0;
    int largestRow=0;
    int largestColumnSum=0;
    int largestColumn=0;

    for(int i=0;i<rows;i++){
        int rowSum=RowSum(matrix[i],columns);
        if(rowSum>largestRowSum){
            largestRowSum=rowSum;
            largestRow=i;
        }
    }

    for(int j=0;j<columns;j++){
        int columnSum=ColumnSum(matrix,rows,j);
        if(columnSum>largestColumnSum){
            largestColumnSum=columnSum;
            largestColumn=j;
        }
    }

    cout<<"Row with the largest sum: "<<largestRow+1<<endl;
    cout<<"Column with the largest sum: "<<largestColumn+1<<endl;
}

int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of columns: ";
    cin>>n;

    int** matrix=new int*[m];

    readMatrix(matrix, m, n);
    printMatrix(matrix, m, n);
    largestSum(matrix, m, n);

    return 0;
}


/*
    ****OUTPUT****

    Enter the number of rows: 3
    Enter the number of columns: 2
    Enter elements of the matrix:
    9
    6
    7
    8
    9
    4
    Matrix:
    9 6 
    7 8 
    9 4 
    Row with the largest sum: 1
    Column with the largest sum: 1

*/