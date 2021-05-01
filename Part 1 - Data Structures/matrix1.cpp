#include <iostream>
#define M 6
#define N 6
using namespace std;

void floodFill(char a[][N],int x,int y,char C0,char C1){
    if(x<0 || x>=M || y<0 || y>=N)
        return;
    if(a[x][y]!=C0)
        return;
    a[x][y]=C1;
    floodFill(a,x+1,y,C0,C1);
    floodFill(a,x-1,y,C0,C1);
    floodFill(a,x,y+1,C0,C1);
    floodFill(a,x,y-1,C0,C1);
}

int main(){
    char a[][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]=='0')
                a[i][j]='-';
        }
    }
    for(int i=0;i<M;i++){
        if(a[i][0]=='-')
            floodFill(a,i,0,'-','0');
    }
    for(int i=0;i<M;i++){
        if(a[i][N-1]=='-')
            floodFill(a,i,N-1,'-','0');
    }
    for(int j=0;j<N;j++){
        if(a[0][j]=='-')
            floodFill(a,0,j,'-','0');
    }
    for(int j=0;j<N;j++){
        if(a[M-1][j]=='-')
            floodFill(a,M-1,j,'-','0');
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]=='-')
                a[i][j]='X';
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
