#include <iostream>
#define N 8
using namespace std;

/*Backtracking: N Queen Problem*/

bool isSafe(int a[N][N],int r,int c){
    int i,j;
    for(i=0;i<c;i++){
        if(a[r][i])
            return false;
    }
    for(i=r,j=c;i>=0 && j>=0;i--,j--){
        if(a[i][j])
            return false;
    }
    for(i=r,j=c;i<N && j>=0;i++,j--){
        if(a[i][j])
            return false;
    }
    return true;
}

bool NQsolution(int a[N][N],int c){
    if(c>=N)
        return true;
    for(int i=0;i<N;i++){
        if(isSafe(a,i,c)){
            a[i][c]=1;
            if(NQsolution(a,c+1))
                return true;
            a[i][c]=0;
        }
    }
    return false;
}

int main(){
    int a[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    if(NQsolution(a,0)){
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


