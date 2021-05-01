#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*Queue: BFS-related problems
bfs,bfs_weightedGraph,bfs_sparseMatrix*/

void bfs(vector<int> graph[], int s, bool visited[]){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int p=q.front(); q.pop();
        cout<<p<<" ";
        for(int i=0;i<graph[p].size();i++){
            if(!visited[graph[p][i]]){
                q.push(graph[p][i]);
                visited[graph[p][i]]=true;
            }
        }
    }
}

void bfs_weightedGraph(vector<pair<int,int> > graph[], int s, bool visited[],int distances[]){
    queue<pair<int,int> > q;
    q.push(make_pair(0,s));
    visited[s] = true;
    distances[s] = 0;
    while(!q.empty()){
        int p=q.front().second; q.pop();
        cout<<p<<" ";
        for(int i=0;i<graph[p].size();i++){
            if(!visited[graph[p][i].second]){
                q.push(graph[p][i]);
                visited[graph[p][i].second]=true;
                distances[graph[p][i].second] = distances[p]+graph[p][i].first;
            }
        }
    }
}

int bfs_sparseMatrix(int matrix[1000][1000],int x, int y, bool visited[1000][1000]){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    visited[x][y]=true;
    int c=1;
    while(!q.empty()){
        int px = q.front().first;
        int py = q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(!visited[px+i][py+j] && matrix[px+i][py+j]){
                    q.push(make_pair(px+i,py+j));
                    visited[px+i][py+j] = true;
                    c++;
                }
            }
        }
    }
    return c;
}

int main(){
    /*int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    int x,y,s;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x].push_back(y);
    }
    cin>>s;
    bool visited[n];
    for (int i = 0; i <n; i++)
        visited[i] = false;

    bfs(graph,s,visited);*/

    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > graph[n];
    int x,y,w,s;
    for(int i=0;i<m;i++){
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(w,y));
    }
    cin>>s;
    bool visited[n];
    int distances[n];
    for (int i = 0; i <n; i++){
        visited[i] = false;
        distances[i] = 0;
    }
    bfs_weightedGraph(graph,s,visited,distances);

    /*int n,m;
    cin>>n>>m;
    int matrix[1000][1000];
    bool visited[1000][1000];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j]=0;
            visited[i][j]=false;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int x,y;
    cin>>x>>y;
    cout<<bfs_sparseMatrix(matrix,x,y,visited);*/

    return 0;
}



