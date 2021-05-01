#include <iostream>
#include <string>
using namespace std;

/*Array: String
*/

void permute(string st,int l,int r){
    if(l==r)
        cout<<st<<endl;
    for(int i=l;i<=r;i++){
        swap(st[i],st[l]);
        permute(st,l+1,r);
        swap(st[i],st[l]);
    }
}

void sortedPermutations(string st){

}

void printCombinations(int a[],int n,int temp[],int r,int i,int j){
    if(i==r){
        for(int k=0;k<r;k++)
            cout<<temp[k]<<" ";
        cout<<endl;
        return;
    }
    if(j>=n)
        return;
    temp[i]=a[j];
    printCombinations(a,n,temp,r,i+1,j+1);
    printCombinations(a,n,temp,r,i,j+1);
}

int main(){
    //string st="ABCD";
    //int n=st.size();
    //permute(st,0,n-1);

    int n=5,r=3;
    int a[]={1,2,3,4,5};
    int temp[3];
    printCombinations(a,n,temp,r,0,0);

    return 0;
}
