#include <iostream>
#include <queue>
#include <deque>
using namespace std;

/*Queue: Array-related problems -- Deque and Priority queue
kMaximums,kMinimums,k1stNegatives,minStringValue*/

vector<int> kMaximums(int a[],int n,int k){
    vector<int> v;
    deque<int> q;
    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()]<=a[i]) q.pop_back();
        q.push_back(i);
    }
    v.push_back(a[q.front()]);

    for(int i=k;i<n;i++){
        while(!q.empty() && q.front()<=i-k) q.pop_front();
        while(!q.empty() && a[q.back()]<=a[i]) q.pop_back();
        q.push_back(i);
        v.push_back(a[q.front()]);
    }
    return v;
}

vector<int> kMinimums(int a[],int n,int k){
    vector<int> v;
    deque<int> q;
    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()]>=a[i]) q.pop_back();
        q.push_back(i);
    }
    v.push_back(a[q.front()]);

    for(int i=k;i<n;i++){
        while(!q.empty() && q.front()<=i-k) q.pop_front();
        while(!q.empty() && a[q.back()]>=a[i]) q.pop_back();
        q.push_back(i);
        v.push_back(a[q.front()]);
    }
    return v;
}

vector<int> k1stNegatives(int a[],int n,int k){
    vector<int> v;
    deque<int> q;
    for(int i=0;i<k;i++){
        if(a[i]<0) q.push_back(i);
    }
    if(!q.empty()) v.push_back(a[q.front()]);
    else v.push_back(0);

    for(int i=k;i<n;i++){
        while(!q.empty() && q.front()<=i-k) q.pop_front();
        if(a[i]<0) q.push_back(i);
        if(!q.empty()) v.push_back(a[q.front()]);
        else v.push_back(0);
    }
}

int minStringValue(string str,int k){
    if(k>=str.length()) return 0;

    int freq[26]={0};
    for(int i=0;i<str.length();i++)
        freq[str[i]-'a']++;

    priority_queue<int> q;
    for(int i=0;i<26;i++)
        q.push(freq[i]);

    while(k--){
        int top=q.top();
        q.pop();
        q.push(top-1);
    }

    int ans=0;
    while(!q.empty()){
        int top=q.top();
        ans+=top*top;
        q.pop();
    }
    return ans;
}

int main(){
    int n = 7;
    int a[] = {2,4,8,7,7,9,3};

    for(int k=1;k<=n;k++){
        vector<int> v = kMaximums(a,n,k);
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }

    string str = "abbccc";
    //cout<<minStringValue(str,2);
    return 0;
}


