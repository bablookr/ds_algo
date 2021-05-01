#include <iostream>
using namespace std;

/*Greedy Algorithms in an Array
minProductSubset,maxProductSubset,*/

int minProductSubset(int a[],int n){
    if(n==1) return a[0];
    int minpos=9999, maxneg=-9999;
    int czero=0, cneg=0;
    int prod=1;
    for(int i=0;i<n;i++){
        if(a[i]>0) minpos = min(minpos,a[i]);
        if(a[i]==0){
            czero++; continue;
        }
        if(a[i]<0){
            cneg++;
            maxneg = max(maxneg,a[i]);
        }
        prod*=a[i];
    }
    if(czero==n || (czero>0 && cneg==0)) return 0;
    if(cneg==0) return minpos;
    if(cneg>0 && cneg%2==0) prod/=maxneg;
    return prod;
}

int maxProductSubset(int a[],int n){
    if(n==1) return a[0];
    int maxneg = -9999;
    int czero=0, cneg=0;
    int prod=1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            czero++; continue;
        }
        if(a[i]<0){
            cneg++;
            maxneg = max(maxneg,a[i]);
        }
        prod*=a[i];
    }
    if(czero==n) return 0;
    if(cneg%2==1){
        if(czero>0 && cneg==1 && czero+cneg==n) return 0;
        prod/=maxneg;
    }
    return prod;
}

int main(){
    int n = 5;
    int a[] = { -1, -1, -2, 4, 3 };

    cout<<maxProductSubset(a,n);
    return 0;
}



