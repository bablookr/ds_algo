#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

/*Directed Graph: Basic Functions
dfs,bfs,detectCycle,topSort*/

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

bool detectCycle(vector<int> graph[],int s, bool visited[],bool recStk[]){
    if(!visited[s]){
        visited[s]=true; recStk[s]=true;
        for (int i = 0; i<graph[s].size(); i++){
            if (!visited[graph[s][i]]){
                if(detectCycle(graph,graph[s][i],visited,recStk)) return true;
            }
            else{
                if(recStk[graph[s][i]]) return true;
            }
        }
    }
    recStk[s]=false;
    return false;
}

void topSort(vector<int> graph[],int s, bool visited[],stack<int> &stk){
    visited[s] = true;
    for (int i = 0; i<graph[s].size(); i++){
        if (!visited[graph[s][i]])
            topSort(graph,graph[s][i],visited,stk);
    }
    stk.push(s);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
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
    bool recStk[n];
    for (int i = 0; i <n; i++){
        visited[i] = false; recStk[i]=false;
    }
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            if(detectCycle(graph,i,visited,recStk))
                cout<<"Found"<<endl; break;
        }
    }

    /*bool visited[n];
    for (int i = 0; i <n; i++)
        visited[i] = false;

    stack<int> stk;
    for (int i = 0; i < n; i++){
        if(!visited[i])
            topSort(graph,i,visited,stk);
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }*/

    return 0;
}
