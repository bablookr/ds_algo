#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Weighted Graph: Basic Functions
dijkstra,prim*/

void dijkstra(vector<pair<int,int> > graph[],int s, bool visited[],int distances[]){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,s));
    distances[s]=0;
    while(!q.empty()){
        int p=q.top().second;
        q.pop();
        visited[p]=true;
        for(int i=0;i<graph[p].size();i++){
            if(!visited[graph[p][i].second]){
                 if(distances[graph[p][i].second]>distances[p]+graph[p][i].first){
                    distances[graph[p][i].second]=distances[p]+graph[p][i].first;
                    q.push(make_pair(distances[graph[p][i].second],graph[p][i].second));
                }
            }
        }
    }
}

int Prim(vector<pair<int,int> > graph[],int s, bool visited[]){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    q.push(make_pair(0,s));
    int minCost=0;
    while(!q.empty()){
        pair<int,int> x =q.top();
        int p = q.top().second;
        q.pop();
        if(visited[p]) continue; //cycle detection
        visited[p]=true;
        minCost+=x.first;
        for(int i=0;i<graph[p].size();i++){
            if(!visited[graph[p][i].second])
                q.push(graph[p][i]);
        }
    }
    return minCost;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > graph[n];
    int x,y,w;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(w,y));
        graph[y].push_back(make_pair(w,x));
    }

    bool visited[n];
    int distances[n];
    for (int i = 0; i <n; i++){
        visited[i] = false;
        distances[i]=9999;
    }
    dijkstra(graph,0,visited,distances);
    for(int i=1;i<n;i++)
        cout<<distances[i]<<" ";

    /*bool visited[n];
    for (int i = 0; i <n; i++)
        visited[i] = false;
    cout<<Prim(graph,0,visited)<<endl;*/

    return 0;
}

