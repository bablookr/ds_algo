#include <iostream>
#include <algorithm>
using namespace std;

/*Array: Two/Three Pointers Method
kadane,maxNonAdjacentSum,maxProduct,findPair,findPairD,findPairClosest,minAbsSumPair,minSumPair,minSumTriple,zeroSumTriple,
findCommon,findClosest,unsortedSubarraay,segregateOddEven,sort01,sort012,isSubset*/

int kadane(int a[],int n){
    int ans = a[0];
    int temp = max(0,a[0]);
    for(int i=1;i<n;i++){
        temp+=a[i];
        ans = max(ans,temp);
        temp = max(0,temp);
    }
    return ans;
}

int maxNonAdjacentSum(int a[],int n){
    int incl = 0, excl = 0, ans = 0;
    for(int i=0;i<n;i++){
        incl = excl+a[i];
        excl = ans;
        ans = max(incl,excl);
    }
    return ans;
}

int maxProduct(int a[],int n){
    int ans=1;
    pair<int,int> temp(1,1);
    for(int i=0;i<n;i++){
        if(a[i]==0) temp = make_pair(1,1);
        else if(a[i]>0) temp = make_pair(temp.first*a[i],min(1,temp.second*a[i]));
        else temp = make_pair(max(1,temp.second*a[i]),temp.first*a[i]);
        ans=max(ans,temp.first);
    }
    return ans;
}

bool findPair(int a[],int n,int sum){
    sort(a,a+n);
    int l = 0, h = n-1;
    bool flag = false;
    while(l<h){
        if(a[l]+a[h]<sum) l++;
        else if(a[l]+a[h]>sum) h--;
        else flag = true;
    }
    return flag;
}

bool findPairD(int a[],int n,int dif){
    sort(a,a+n);
    int l = 0, h = 1;
    bool flag = false;
    while(l<n && h<n){
        if(h!=l && a[h]-a[l]==dif) flag = true;
        else if(a[h]-a[l]<dif) h++;
        else l++;
    }
    return flag;
}

pair<int,int> findPairClosest(int a[],int n,int sum){
    sort(a,a+n);
    int l = 0, h = n-1, mindif = 9999;
    int minl = 0, minh = n-1;
    while(l<h){
        int dif = a[l]+a[h]-sum;
        if(dif<0) dif = -dif;
        if(dif<mindif){
            mindif = dif;
            minl = l; minh = h;
        }
        if(a[l]+a[h]>sum) h--;
        else l++;
    }
    return make_pair(a[minl],a[minh]);
}

pair<int,int> minAbsSumPair(int a[],int n){
    sort(a,a+n);
    int l = 0, h = n-1, minsum=9999;
    int minl = 0, minh = n-1;
    while(l<h){
        int sum = a[l]+a[h];
        if(sum<0) sum = -sum;
        if(sum<minsum){
            minsum = sum;
            minl = l; minh = h;
        }
        if(sum<0) l++;
        else h--;
    }
    return make_pair(a[minl],a[minh]);
}

pair<int,int> minSumPair(int a[],int n){
    int min1=9999,min2=9999;
    if(n>1){
        for(int i=0;i<n;i++){
            if(a[i]<min1){
                min2 = min1; min1 = a[i];
            }
            else if(a[i]!=min1 && a[i]<min2) min2 = a[i];
        }
    }
    return make_pair(min1,min2);
}

void minSumTriple(int a[],int n){
    int min1=9999, min2=9999, min3=9999;
    if(n>3){
        for(int i=0;i<n;i++){
            if(a[i]<min1){
                min3=min2; min2=min1; min1=a[i];
            }
            else if(a[i]<min2){
                min3=min2; min2=a[i];
            }
            else if(a[i]<min3){
                min3=a[i];
            }
        }
        cout<<min1<<" "<<min2<<" "<<min3<<endl;
    }
}

void zeroSumTriple(int a[],int n){
    sort(a,a+n);
    bool flag = false;
    for(int i=0;i<n-1;i++){
        int l = i+1, h = n-1;
        while(l<h){
            if(a[i]+a[l]+a[h]==0){
                cout<<a[i]<<" "<<a[l]<<" "<<a[h]<<endl;
                l++; h--;
                flag = true;
            }
            else if(a[i]+a[l]+a[h]<0) l++;
            else h--;
        }
    }
}

void findCommon(int a1[],int a2[],int a3[],int n1,int n2,int n3){
    sort(a1,a1+n1); sort(a2,a2+n2); sort(a3,a3+n3);
    int i=0,j=0,k=0;
    while(i<n1 && j<n2 && k<n3){
        if(a1[i]==a2[j] && a2[j]==a3[k]){
            cout<<a1[i]<<endl;
            i++; j++; k++;
        }
        else if(a1[i]<a2[j]) i++;
        else if(a2[j]<a3[k]) j++;
        else k++;
    }
}

void findClosest(int a1[],int a2[],int a3[],int n1,int n2,int n3){
    sort(a1,a1+n1); sort(a2,a2+n2); sort(a3,a3+n3);
    int ansi = 0, ansj = 0, ansk = 0;
    int i = 0, j = 0, k = 0;
    int dif = 9999;
    while(i<n1 && j<n2 && k<n3){
        int mi = min(a1[i],min(a2[j],a3[k]));
        int ma = max(a1[i],max(a2[j],a3[k]));

        if(ma-mi<dif){
            ansi = i; ansj = j; ansk = k;
            dif = ma-mi;
        }

        if(dif==0) break;
        if(a1[i]==mi) i++;
        else if(a2[j]==mi) j++;
        else k++;
    }
    cout<<a1[ansi]<<" "<<a2[ansj]<<" "<<a3[ansk]<<endl;
}

void unsortedSubarraay(int a[],int n){
    int l=0,h=n-1;
    int mi,ma;

    for(l=0;l<n-1;l++){
        if(a[l]>a[l+1]) break;
    }
    if(l==n-1) return;
    for(h=n-1;h>0;h--){
        if(a[h]<a[h-1]) break;
    }

    mi=a[l]; ma=a[l];
    for(int i=l+1;i<=h;i++){
        if(a[i]>ma) ma = a[i];
        if(a[i]<mi) mi = a[i];
    }

    for(int i=0;i<l;i++){
        if(a[i]>mi){
            l = i; break;
        }
    }
    for(int i=n-1;i>=h+1;i--){
        if(a[i]<ma){
            h = i; break;
        }
    }
    cout<<l<<" "<<h<<endl;
    return;
}

void segregateOddEven(int a[],int n){
    int l = 0, h = n-1;
    int k = 0;
    while(l<h){
        while(a[l]%2!=0){
            l++; k++;
        }
        while(l<h && a[h]%2==0) h--;
        if(l<h) swap(a[l],a[h]);
    }
    sort(a,a+k,greater<int>());
    sort(a+k,a+n);
}

void sort01(int a[],int n){
    int l=0,h=n-1;
    while(l<h){
        if(a[l]==1) swap(a[l],a[h--]);
        else l++;
    }
}

void sort012(int a[],int n){
    int l=0,h=n-1;
    int mid = 0;
    while(mid<=h){
        if(a[mid]==0) swap(a[l++], a[mid++]);
        else if(a[mid]==1) mid++;
        else swap(a[mid], a[h--]);
    }
}

bool isSubset(int a1[],int a2[],int n1,int n2){
    if(n1<n2) return false;

    sort(a1,a1+n1); sort(a2,a2+n2);

    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]) i++;
        else if(a1[i]==a2[j]){
            i++; j++;
        }
        else return false;
    }

    if(j<n2) return false;
    return true;
}

int main(){
    int n = 6;
    int a[] ={1, 3, 2, 7, 5, 4};
    segregateOddEven(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    //cout<<kadane(a,n)<<endl;
    return 0;
}




