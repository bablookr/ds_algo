#include <iostream>
#define N 4
using namespace std;

/*Backtracking: Maze Problem*/

bool MazeSolution(int a[N][N],int sol[N][N],int x,int y){
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }
    if(x>=0 && x<N && y>=0 && y<N && a[x][y]==1){
        sol[x][y]=1;
        if(MazeSolution(a,sol,x+1,y) || MazeSolution(a,sol,x,y+1))
            return true;
        sol[x][y]=0;
        return false;
    }
    return false;
}

int main(){
    int a[N][N]={ {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    int sol[N][N] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};

    if(MazeSolution(a,sol,0,0)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"No Solution"<<endl;
    return 0;
}

