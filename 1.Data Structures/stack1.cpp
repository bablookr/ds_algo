#include <iostream>
#include <stack>
using namespace std;

/*Stack: Basic functions
pushTop,pushBottom,ins,del,reverse_stack,sort_stack,linear_search*/

void pushTop(stack<int> &stk,int key){
    stk.push(key);
}

void pushBottom(stack<int> &stk,int key){
    if(stk.empty()){
        stk.push(key);
        return;
    }
    int top=stk.top();
    stk.pop();
    pushBottom(stk,key);
    stk.push(top);
}

void ins(stack<int> &stk,int key,int n){
    if(n==0){
        stk.push(key);
        return;
    }
    int top=stk.top();
    stk.pop();
    ins(stk,key,n-1);
    stk.push(top);
}

void del(stack<int> &stk,int n){
    if(n==0){
        stk.pop();
        return;
    }
    int top=stk.top();
    stk.pop();
    del(stk,n-1);
    stk.push(top);
}

void reverse_stack(stack<int> &stk){
    if(stk.empty()) return;
    int top=stk.top();
    stk.pop();
    reverse_stack(stk);
    pushBottom(stk,top);
}

void sortedInsert(stack<int> &stk,int key){
    //Constraint: Stack should be sorted
    if(stk.empty() || key>=stk.top()){
        stk.push(key);
        return;
    }
    int top=stk.top();
    stk.pop();
    sortedInsert(stk,key);
    stk.push(top);
}

void sort_stack(stack<int> &stk){
    if(stk.empty()) return;
    int top=stk.top();
    stk.pop();
    sort_stack(stk);
    sortedInsert(stk,top);
}

bool linear_search(stack<int> stk,int key){
    if(stk.empty()) return false;
    if(stk.top()==key) return true;
    stk.pop();
    return linear_search(stk,key);
}

int main(){
    stack<int> stk;
    stk.push(1);
    stk.push(3);
    stk.push(5);
    stk.push(7);
    stk.push(9);

    //sort_stack(stk);
    //if(linear_search(stk,3)) cout<<"Yes"<<endl;

    while(!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();
    }
    return 0;
}
