#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*Stack: Array-related problems -- Next Greater/Smaller Element
NGEright,NSEright,NGEleft,NSEleft,maxOfkMinimums,minOfkMaximums*/

vector<int> NGEright(int a[],int n){
    vector<int> right(n,-1);
    stack<int> stk;
    for (int i=0;i<n;i++){
        while (!stk.empty() && a[stk.top()]<a[i]){
            right[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return right;
}

vector<int> NSEright(int a[],int n){
    vector<int> right(n,-1);
    stack<int> stk;
    for (int i=0;i<n;i++){
        while (!stk.empty() && a[stk.top()]>a[i]){
            right[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return right;
}

vector<int> NGEleft(int a[],int n){
    vector<int> left(n,-1);
    stack<int> stk;
    for (int i=n-1;i>=0;i--){
        while (!stk.empty() && a[stk.top()]<a[i]){
            left[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return left;
}

vector<int> NSEleft(int a[],int n){
    vector<int> left(n,-1);
    stack<int> stk;
    for (int i=n-1;i>=0;i--){
        while (!stk.empty() && a[stk.top()]>a[i]){
            left[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return left;
}

vector<int> maxOfkMinimums(int a[],int n){
    vector<int> v(n,0);
    vector<int> left = NSEleft(a,n);
    vector<int> right = NSEright(a,n);
    for(int i=0;i<n;i++){
        if(right[i]==-1) right[i]=n;
    }
    for(int i=0;i<n;i++){
        int len = right[i]-left[i]-2;
        v[len] = max(v[len],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        v[i] = max(v[i],v[i+1]);
    }
    return v;
}

vector<int> minOfkMaximums(int a[],int n){
    vector<int> v(n,10000);
    vector<int> left = NGEleft(a,n);
    vector<int> right = NGEright(a,n);
    for(int i=0;i<n;i++){
        if(right[i]==-1) right[i]=n;
    }
    for(int i=0;i<n;i++){
        int len = right[i]-left[i]-2;
        v[len] = min(v[len],a[i]);
    }
    for(int i=n-2;i>=0;i--){
       v[i] = min(v[i],v[i+1]);
    }
    return v;
}

int main(){
    int n=7;
    int a[]={2,4,8,7,7,9,3};

    vector<int> v= minOfkMaximums(a,n);
    for(int i=0;i<n;i++)
        cout<<v[i]<<endl;

    return 0;
}
