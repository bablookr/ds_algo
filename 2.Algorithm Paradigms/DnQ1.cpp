#include <iostream>
using namespace std;

/*DnQ: Searching
binarySearch,almostSortedSearch,searchFixedPoint,findMissingAP,insertPosition,floorSearch,ceilSearch,closestNumber,findCrossover,findCrossoverBinary,searchOddTimesAppearings,findPeak,findPivot,pivotedSearch,pivotedBinarySearch*/

int binarySearch(int a[],int l,int h,int x){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;
    if(x<a[mid]) return binarySearch(a,l,mid-1,x);
    return binarySearch(a,mid+1,h,x);
}

int almostSortedSearch(int a[],int l,int h,int x){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid==x]) return mid;
    if(mid>l && a[mid-1]==x) return mid-1;
    if(mid<h && a[mid+1]==x) return mid+1;
    if(x<a[mid]) return almostSortedSearch(a,l,mid-2,x);
    return almostSortedSearch(a,mid+2,h,x);
}

int searchFixedPoint(int a[],int l,int h){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid]==mid) return mid;
    if(a[mid]<mid) return searchFixedPoint(a,mid+1,h);
    return searchFixedPoint(a,l,mid-1);
}

int findMissingAP(int a[],int l,int h,int d){
    if(l>=h) return 9999;
    int mid = (l+h)/2;
    if(mid<h && a[mid+1]-a[mid]!=d) return a[mid]+d;
    if(mid>l && a[mid]-a[mid-1]!=d) return a[mid-1]+d;
    if(a[mid]==a[0]+d*mid) return findMissingAP(a,mid+1,h,d);
    return findMissingAP(a,l,mid-1,d);
}

int insertPosition(int a[],int l,int h,int x){
    if(l>=h) return (x>a[l])?(l+1):l;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid+1;
    if(a[mid]<x) return insertPosition(a,mid+1,h,x);
    return insertPosition(a,l,mid-1,x);
}

int floorSearch(int a[],int l,int h,int x){
    if(x<a[l]) return -1;
    if(x>=a[h]) return h;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;
    else if(x<a[mid]){
        if(mid>l && a[mid-1]<=x) return mid-1;
        return floorSearch(a,l,mid-1,x);
    }
    else if(a[mid]<x){
        if(mid<h && x<a[mid+1]) return mid;
        return floorSearch(a,mid+1,h,x);
    }

}

int ceilSearch(int a[],int l,int h,int x){
    if(x>a[h]) return -1;
    if(x<=a[l]) return l;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;
    else if(a[mid]<x){
        if(mid<h && x<=a[mid+1]) return mid+1;
        return ceilSearch(a,mid+1,h,x);
    }
    else if(x<a[mid]){
        if(mid>l && a[mid-1]<x) return mid;
        return ceilSearch(a,l,mid-1,x);
    }
}

int closestNumber(int a[],int l,int h,int x){
    if(x<=a[l]) return l;
    if(x>=a[h]) return h;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;
    if(x<a[mid]){
        if(mid>l && a[mid-1]<x) return (x-a[mid-1]>=a[mid]-x)?mid:(mid-1);
        return closestNumber(a,l,mid-1,x);
    }
    else if(a[mid]<x){
        if(mid<h && a[mid+1]>x) return (x-a[mid]>=a[mid+1]-x)?(mid+1):mid;
        return closestNumber(a,mid+1,h,x);
    }
}

int findCrossover(int a[],int l,int h,int x){
    if(x<a[l]) return l;
    if(x>=a[h]) return h;
    int mid = (l+h)/2;
    if(a[mid]<=x && x<a[mid+1]) return mid;
    if(a[mid]<x) return findCrossover(a,mid+1,h,x);
    return findCrossover(a,l,mid-1,x);
}

int findCrossoverBinary(int a[],int l,int h){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if((mid==h) || (a[mid]==1 && a[mid+1]==0)) return mid+1;
    if(a[mid]==1) return findCrossoverBinary(a,mid+1,h);
    return findCrossoverBinary(a,l,mid-1);
}

int searchOddTimesAppearings(int a[],int l,int h){
    if(l>h) return -1;
    if(l==h) return a[l];
    int mid = (l+h)/2;
    if(mid%2==0){
        if(a[mid]==a[mid+1]) return searchOddTimesAppearings(a,mid+2,h);
        return searchOddTimesAppearings(a,l,mid);
    }
    else{
        if(a[mid]==a[mid-1]) return searchOddTimesAppearings(a,mid+1,h);
        return searchOddTimesAppearings(a,l,mid-1);
    }
}

int findPeak(int a[],int l,int h){
    if(h==l) return a[l];
    if(h==l+1) return max(a[l],a[h]);
    int mid = (l+h)/2;
    if(a[mid-1]<a[mid] && a[mid]>a[mid+1]) return mid;
    if(a[mid-1]>a[mid] && a[mid]>a[mid+1]) return findPeak(a,l,mid-1);
    else return findPeak(a,mid+1,h);
}

int findPivot(int a[],int l,int h){
    if(l>h) return -1;
    if(l==h) return l;
    int mid = (l+h)/2;
    if(mid<h && a[mid]>a[mid+1]) return mid;
    if(mid>l && a[mid]<a[mid-1]) return mid-1;
    if(a[mid]<=a[l]) return findPivot(a,l,mid-1);
    return findPivot(a,mid+1,h);
}

int pivotedSearch(int a[],int n,int x){
    int pivot = findPivot(a,0,n-1);
    if(pivot==-1) return binarySearch(a,0,n-1,x);
    if(a[pivot]==x) return pivot;
    if(a[0]<=x) return binarySearch(a,0,pivot-1,x);
    return binarySearch(a,pivot+1,n-1,x);
}

int pivotedBinarySearch(int a[],int l,int h,int x){
    if(l>h) return -1;
    int mid = (l+h)/2;
    if(a[mid]==x) return mid;

    if(a[l]<=a[mid]){
        if(a[l]<=x && a[mid]>=x) return pivotedBinarySearch(a,l,mid-1,x);
        return pivotedBinarySearch(a,mid+1,h,x);
    }

    if(a[mid]<=x && x<=a[h]) return pivotedBinarySearch(a,mid+1,h,x);
    return pivotedBinarySearch(a,l,mid-1,x);
}

/*DnQ: Sorting
quickSelect*/

int quickSelect(int a[],int l,int h,int k){
    if(k<=0 || k>h-l+1) return 999999;

    int pivot = h, j = l-1;
    for(int i=l;i<h;i++){
        if(a[i]<=a[h]) swap(a[i],a[++j]);
    }
    swap(a[h],a[++j]);

    if(j==l+k-1) return a[j];
    if(j>l+k-1) return quickSelect(a,l,j-1,k);
    return quickSelect(a,j+1,h,l+k-1-j);
}

int quickSelect2(int a1[],int a2[],int n1,int n2){

}

int getMedian(int a[],int b[],int n){
    if(n<=0) return -1;
    if(n==1) return (a[0]+b[0])/2;
    if(n==2) return (max(a[0],b[0])+min(a[1],b[1]))/2;

    int median1 = (n%2==1)?a[n/2]:(a[n/2-1]+a[n/2])/2;
    int median2 = (n%2==1)?b[n/2]:(b[n/2-1]+b[n/2])/2;

    if(median1==median2) return median1;
    else if(median1<median2){
        if(n%2==1) return getMedian(a+n/2,b,n-n/2);
        return getMedian(a+n/2-1,b,n-n/2+1);
    }
    else{
        if(n%2==1) return getMedian(b+n/2,a,n-n/2);
        return getMedian(b+n/2-1,a,n-n/2+1);
    }
}

int getMinMax(int a[],int l,int h){

}

int invCountMerge(int a[],int l,int m,int h,int temp[]){
    int c=0;
    int i=l,j=m,k=l;
    while(i<m && j<=h){
        if(a[i]<=a[j]) temp[k++] = a[i++];
        else{
            temp[k++] = a[j++];
            c+=(m-i);
        }
    }
    while(i<m) temp[k++] = a[i++];
    while(j<=h) temp[k++] = a[j++];
    for(i=l;i<=h;i++) a[i] = temp[i];
    return c;
}

int invCountSort(int a[],int l,int h,int temp[]){
    int invCount = 0;
    if(l<h){
        int mid = (l+h)/2;
        invCount+= invCountSort(a,l,mid,temp);
        invCount+= invCountSort(a,mid+1,h,temp);
        invCount+= invCountMerge(a,l,mid+1,h,temp);
    }
    return invCount;
}

int main(){
    int n = 6;
    int a[] = {5, 6, 1, 2, 3, 4};
    cout<<a[findPivot(a,0,n-1)];
    return 0;
}

