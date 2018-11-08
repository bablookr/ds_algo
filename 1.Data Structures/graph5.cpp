#include <iostream>
#include <queue>
using namespace std;

/*Adjacency Matrix: Basic Functions
FloydWarshall,bipartile*/

void FloydWarshall(int graph[1000][1000],int distances[1000][1000],int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(distances[i][j]>distances[i][k]+distances[k][j])
                    distances[i][j]=distances[i][k]+distances[k][j];
            }
        }
    }
}

bool bipartile(int graph[1000][1000],int n){
    int color[n];
    for(int i=0;i<n;i++) color[i] = -1;
    color[0] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int p = q.front(); q.pop();
        if(graph[p][p]==1) return false;
        for(int i=0;i<n;i++){
            if(graph[p][i] && color[i]==-1){
                color[i] = 1-color[p];
                q.push(i);
            }
            else if(graph[p][i] && color[p]==color[i])
                return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    int graph[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            graph[i][j]=1000000000;
    }
    for(int i=0;i<n;i++)
        graph[i][i]=0;
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        graph[x][y]=w;
    }
    int distances[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            distances[i][j]=graph[i][j];
    }
    FloydWarshall(graph,distances,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<distances[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}



