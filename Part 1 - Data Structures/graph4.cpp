#include <iostream>
#include <vector>

using namespace std;

/*Negative Edge Graph: Basic Functions
BellmanFord,detectCycleNegative*/

void BellmanFord(vector<int> graph[],int n, int m,int distances[]){
    distances[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            if(distances[graph[j][1]]>graph[j][2]+distances[graph[j][0]])
            	distances[graph[j][1]]=graph[j][2]+distances[graph[j][0]];
        }
    }
}

bool detectCycleNegative(vector<int> graph[],int n,int m){

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[m];
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        graph[i].push_back(x-1);
        graph[i].push_back(y-1);
        graph[i].push_back(w);
    }
    int distances[n];
    for (int i = 0; i <n; i++)
        distances[i]=9999;

    BellmanFord(graph,n,m,distances);
    for(int i=0;i<n;i++)
        cout<<distances[i]<<" ";
    return 0;
}

