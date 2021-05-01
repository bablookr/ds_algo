#include <iostream>
#include <algorithm>
using namespace std;

/*Array: Basic functions
insert,delete,reverse,sort,search*/

void ins(int a[],int n){

}

void del(int a[],int n){

}

void reverse_array(int a[],int n){
    reverse(a,a+n);
}

void sort_array(int a[],int n){
    sort(a,a+n);
    //sort(a,a+n,greater<int>());
}

void search_array(int a[],int n,int x){
    //Constraint: Array should be sorted.
    if(binary_search(a,a+n,x)) cout<<"Found"<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    sort_array(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;

    return 0;
}
