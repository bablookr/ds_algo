#include <iostream>
using namespace std;

void buildMaxHeap(int a[],int n){
    for(int i=1;i<n;i++){
        if(a[i]>a[(i-1)/2]){
            int j = i;
            while(a[j]>a[(j-1)/2]){
                swap(a[j],a[(j-1)/2]);
                j = (j-1)/2;
            }
        }
    }
}

void heapSort(int a[],int n){
    buildMaxHeap(a,n);
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        int j = 0, index;
        do{
            index = 2*j+1;
            if(a[index]<a[index+1] && index<i-1) index++;
            if(a[j]<a[index] && index<i) swap(a[j],a[index]);
            j = index;
        }while(index<i);
    }
}

int main(){
    int n = 6;
    int a[] = {10, 20, 15, 17, 9, 21};
    heapSort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
