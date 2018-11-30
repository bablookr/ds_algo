#include <iostream>
using namespace std;

int st[1000] = {0};

void build(int a[],int l,int h,int i){
    if(l==h) st[i] = a[l];
    else{
        int mid = (l+h)/2;
        build(a,l,mid,2*i+1);
        build(a,mid+1,h,2*i+2);
        st[i] = min(st[2*i+1],st[2*i+2]);
    }
}

int rangeMin(int ql,int qh,int l,int h,int i){
    if(qh<l || h<ql) return 9999999;
    if(ql<=l && h<=qh) return st[i];
    int mid = (l+h)/2;
    return min(rangeMin(ql,qh,l,mid,2*i+1),rangeMin(ql,qh,mid+1,h,2*i+2));
}

void update(int index,int val,int l,int h,int i){
    if(index<l || index>h) return;
    if(l==h) st[i]=val;
    if(l!=h){
        int mid = (l+h)/2;
        update(index,val,l,mid,2*i+1);
        update(index,val,mid+1,h,2*i+2);
        st[i] = min(st[2*i+1],st[2*i+2]);
    }
}

int main(){
    int n = 6;
    int a[] = {1, 3, 5, 7, 9, 11};

    build(a,0,5,0);
    update(1,2,0,5,0);
    cout<<rangeMin(1,5,0,5,0)<<endl;
    return 0;
}
