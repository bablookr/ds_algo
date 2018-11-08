#include <iostream>
using namespace std;

/* DP: Array-related problems
LIS,isSubsetSum,knapsack01,coinChangeWays,maxRodCutPrice,pivotIndex*/

int LIS(int a[],int n){
    int dp[n],ans=1;
    dp[0] = 1;
    for(int i=1;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(a[i]>a[j] && dp[i]<=dp[j]) dp[i]=dp[j]+1;
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

bool isSubsetSum(int a[],int n,int sum){
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++) dp[i][0] = true;
    for(int i=1;i<=sum;i++) dp[0][i] = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j<a[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i-1]];
        }
    }
    return dp[n][sum];
}

int knapsack01(int w[],int v[],int n,int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=sum;i++) dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(w[i-1]<=j) dp[i][j] = max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int coinChangeWays(int a[],int n,int sum){
    int dp[sum+1][n];
    for(int i=0;i<=sum;i++){
        for(int j=0;j<n;j++) dp[i][j] = 0;
    }

    for(int i=0;i<n;i++) dp[0][i] = 1;

    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]) dp[i][j]+=dp[i-a[j]][j];
            if(j>=1) dp[i][j]+=dp[i][j-1];
        }
    }
    return dp[sum][n-1];
}

int maxRodCutPrice(int a[],int n){
    int dp[n+1];
    for(int i=0;i<=n;i++) dp[i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            dp[i] = max(dp[i],dp[i-j-1]+a[j]);
    }
    return dp[n];
}

int pivotIndex(int a[],int n){
    int leftMax[n],rightMin=9999;
    leftMax[0] = -9999;
    for(int i=1;i<n;i++)
        leftMax[i] = max(leftMax[i-1],a[i-1]);
    for(int i=n;i>=0;i--){
        if(leftMax[i]<a[i] && a[i]<rightMin) return i;
        rightMin = min(rightMin,a[i]);
    }
    return -1;
}

int main(){
    //int n = 9;
    //int a[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};

    //int a[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    //cout<<LIS(a,8);

    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    //cout<<maxRodCutPrice(arr,8);

    int a[] = {24,20};
    int b[] = {20,19};
    cout<<knapsack01(b,a,2,50);
    //if(isSubsetSum(a,n,9)) cout<<"Yes";
    //cout<<pivotIndex(a,n)<<endl;
    return 0;
}



