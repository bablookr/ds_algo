#include <iostream>
using namespace std;

int st[1000] = {0};

void build(int a[],int l,int h,int i){
    if(l==h) st[i] = a[l];
    else{
        int mid = (l+h)/2;
        build(a,l,mid,2*i+1);
        build(a,mid+1,h,2*i+2);
        st[i] = st[2*i+1]+st[2*i+2];
    }
}

int rangeSum(int ql,int qh,int l,int h,int i){
    if(qh<l || h<ql) return 0;
    if(ql<=l && h<=qh) return st[i];
    int mid = (l+h)/2;
    return rangeSum(ql,qh,l,mid,2*i+1)+rangeSum(ql,qh,mid+1,h,2*i+2);
}

void update(int index,int diff,int l,int h,int i){
    if(index<l || index>h) return;
    st[i] = st[i]+diff;
    if(h!=l){
        int mid = (l+h)/2;
        update(index,diff,l,mid,2*i+1);
        update(index,diff,mid+1,h,2*i+2);
    }
}

void updateRange(int ql,int qh,int diff,int l,int h,int i){
    if(l>h || qh<l || h<ql) return;
    if(l==h){
        st[i] = st[i]+diff; return;
    }
    int mid = (l+h)/2;
    updateRange(ql,qh,diff,l,mid,2*i+1);
    updateRange(ql,qh,diff,mid+1,h,2*i+2);
    st[i] = st[2*i+1]+st[2*i+2];
}

int main(){
    int n = 6;
    int a[] = {1, 3, 5, 7, 9, 11};

    build(a,0,5,0);
    update(2,5,0,5,0);
    //updateRange(2,2,5,0,5,0);
    cout<<rangeSum(1,5,0,5,0)<<endl;
    return 0;
}

