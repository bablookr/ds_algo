#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Undirected Graph: Basic Functions
dfs,bfs,cycleDetect*/

void dfs(vector<int> graph[],int s, bool visited[]){
    visited[s] = true;
    cout<<s<<" ";
    for (int i = 0; i<graph[s].size(); i++){
        if (!visited[graph[s][i]])
            dfs(graph,graph[s][i],visited);
    }
}

void bfs(vector<int> graph[],int s, bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        cout<<p<<" ";
        for(int i=0;i<graph[p].size();i++){
            if(!visited[graph[p][i]]){
                q.push(graph[p][i]);
                visited[graph[p][i]]=true;
            }
        }
    }
}

bool detectCycle(vector<int> graph[],int s, bool visited[],int parent){
    visited[s]=true;
    for (int i = 0; i<graph[s].size(); i++){
        if (!visited[graph[s][i]]){
            if(detectCycle(graph,graph[s][i],visited,s)) return true;
        }
        else{
            if(graph[s][i]!=parent) return true;
        }
    }
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    /*bool visited[n];
    for (int i=0;i<n;i++)
        visited[i] = false;

    for (int i=0;i<n;i++){
        if(!visited[i])
            dfs(graph,i,visited);
    }*/

    /*bool visited[n];
    for (int i=0;i<n;i++)
        visited[i] = false;

    for (int i=0;i<n;i++){
        if(!visited[i])
            bfs(graph,i,visited);
    }*/

    bool visited[n];
    for (int i = 0; i <n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++){
        if(!visited[i]){
            if(detectCycle(graph,i,visited,-1))
                cout<<"Found"<<endl; break;
        }
    }

    return 0;
}
