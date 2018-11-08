#include <iostream>
#define N 8
using namespace std;

/*Backtracking: Knight Tour Problem*/

bool KTsolution(int a[N][N],int x,int y,int moven,int moveX[],int moveY[]){
    if(moven==N*N)
        return true;
    for(int i=0;i<N;i++){
        int nextX=x+moveX[i];
        int nextY=y+moveY[i];
        if(nextX>=0 && nextX<N && nextY>=0 && nextY<N && a[nextX][nextY]==-1){
            a[nextX][nextY]=moven;
            if(KTsolution(a,nextX,nextY,moven+1,moveX,moveY))
                return true;
            else
                a[nextX][nextY]=-1;

        }
    }
    return false;
}

int main(){
    int a[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            a[i][j]=-1;
    }
    a[0][0]=0;
    int moveX[] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int moveY[] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    if(KTsolution(a,0,0,1,moveX,moveY)){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                cout<<a[i][j]<<"\t";
            cout<<endl;
        }
    }
    else
        cout<<"No Solution"<<endl;
    return 0;
}

