#include <iostream>
#include <queue>
using namespace std;

/*Queue: Basic functions
pushBack,pushFront,ins,del,reverse_queue,sort_queue,linear_search*/

void pushBack(queue<int> &q,int key){
    q.push(key);
}

void pushFront(queue<int> &q,int key){
    queue<int> res;
    res.push(key);
    while(!q.empty()){
        res.push(q.front());
        q.pop();
    }
    q=res;
}

void ins(queue<int> &q,int key,int n){
    queue<int> res;
    for(int i=0;i<n;i++){
        res.push(q.front());
        q.pop();
    }
    res.push(key);
    while(!q.empty()){
        res.push(q.front());
        q.pop();
    }
    q=res;
}

void del(queue<int> &q,int n){
     queue<int> res;
    for(int i=0;i<n;i++){
        res.push(q.front());
        q.pop();
    }
    while(!q.empty()){
        res.push(q.front());
        q.pop();
    }
    q=res;
}

void reverse_queue(queue<int> &q){
    if(q.empty()) return;
    int top=q.front();
    q.pop();
    reverse_queue(q);
    q.push(top);
}

int findMin(queue<int> &q,int sortedIndex){
    int minIndex = -1, minVal = 99999;
    int n = q.size();
    for(int i=0; i<n; i++){
        int top = q.front();
        q.pop();
        if(top<=minVal && i<=sortedIndex){
            minIndex = i;
            minVal = top;
        }
        q.push(top);
    }
    return minIndex;
}

void sort_queue(queue<int> &q){
    int minIndex, minVal;
    int n=q.size();
    for(int i=0;i<n;i++){
        minIndex = findMin(q,n-1-i);
        for(int j = 0; j < n; j++){
            int top = q.front();
            q.pop();
            if (j != minIndex) q.push(top);
            else minVal = top;
        }
        q.push(minVal);
    }
}

bool linear_search(queue<int> q,int key){
    if(q.empty()) return false;
    if(q.front()==key) return true;
    q.pop();
    return linear_search(q,key);
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(6);
    q.push(8);
    q.push(7);
    q.push(9);

    //sort_queue(q);
    //if(linear_search(q,3)) cout<<"Yes"<<endl;

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}

