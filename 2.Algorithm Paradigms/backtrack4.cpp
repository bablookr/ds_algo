#include <iostream>
#define N 9
using namespace std;

/*Backtracking: Sudoku*/

bool isSolved(int a[N][N],int &i,int &j){
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(a[i][j]==0)
                return false;
        }
    }
    return true;
}

bool isSafe(int a[N][N],int r,int c,int n){
    for(int i=0;i<N;i++){
        if(a[i][c]==n)
            return false;
    }
    for(int j=0;j<N;j++){
        if(a[r][j]==n)
            return false;
    }
    int r0=r-r%3,c0=c-c%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[r0+i][c0+j]==n)
                return false;
        }
    }
    return true;
}

bool SudokuSolution(int a[N][N]){
    int r,c;
    if(isSolved(a,r,c))
        return true;
    for(int n=1;n<=9;n++){
        if(isSafe(a,r,c,n)){
            a[r][c]=n;
            if(SudokuSolution(a))
                return true;
            a[r][c]=0;
        }
    }
    return false;
}

int main(){
    int a[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(SudokuSolution(a)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"No Solution"<<endl;
    return 0;
}
