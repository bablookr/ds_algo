#include <iostream>
#define MAX 100
using namespace std;

/*Array: Searching and Sorting
binary_search,quick_sort,merge_sort,bubble_sort,insertion_sort,selection_sort,count_sort,minSwapsToSort*/

int binarySearch(int a[],int l,int h,int x){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;
    if(a[mid]>x) return binarySearch(a,l,mid-1,x);
    return binarySearch(a,mid+1,h,x);
}

void quick_sort(int a[],int l,int h){
    if(l>=h) return;

    int pivot=h,j=l-1;
    for(int i=l;i<h;i++){
        if(a[i]<=a[pivot]) swap(a[i],a[++j]);
    }
    swap(a[h],a[++j]);

    quick_sort(a,l,j-1);
    quick_sort(a,j+1,h);
}

void merge_sort(int a[],int l,int h){
    if(l>=h) return;

    int mi=(l+h)/2, n1=mi-l+1,n2=h-mi;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int i=0;i<n2;i++)
        R[i]=a[mi+i+1];

    merge_sort(L,0,n1-1);
    merge_sort(R,0,n2-1);

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void bubble_sort(int a[],int n){

}

void insertion_sort(int a[],int n){

}

void selection_sort(int a[],int n){

}

void count_sort(int a[],int n){
    int i,j,ar[1000]={0},c[1000]={0};
    for(i=0;i<n;i++)
        c[a[i]]++;
    for(j=1;j<=MAX;j++)
        c[j]+=c[j-1];
    for(i=n-1;i>=0;i--){
        ar[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(i=0;i<n;i++)
        a[i]=ar[i];
}

int minSwapsToSort(int a[],int n){
    pair<int,int> pos[n];
    bool visited[n];
    for(int i=0;i<n;i++){
        pos[i].first = a[i];
        pos[i].second = i;
        visited[i] = false;
    }
    sort(pos,pos+n);
    int c = 0;
    for(int i=0;i<n;i++){
        if(visited[i] || pos[i].second==i) continue;
        int cycle = 0,j=i;
        while(!visited[j]){
            visited[j]=true;
            j = pos[j].second;
            cycle++;
        }
        c+= (cycle-1);
    }
    return c;
}

int main(){
    int i,n,a[100]={0};
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];

    quick_sort(a,0,n-1);//

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
