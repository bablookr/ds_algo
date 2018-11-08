#include <iostream>
#define MAX 5
using namespace std;

/*DP: Matrix-related problems
matrixChainMul,maxSumSubmatrix*/

int matrixChainMul(int a[],int n){
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) dp[i][j] = 99999;
    }

    for(int i=1;i<n;i++) dp[i][i] = 0;

    for(int l=2;l<n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            for(int k=i;k<j;k++) dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
        }
    }
    return dp[1][n-1];
}

int maxGold(int a[][MAX],int m,int n){
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) dp[i][j] = 0;
    }
    for(int j=n-1;j>=0;j--){
        for(int i=0;i<m;i++){
            int right = (j==n-1)?0:dp[i][j+1];
            int rightup = (i==0 || j==n-1)?0:dp[i-1][j+1];
            int rightdown = (i==m-1 || j==n-1)?0:dp[i+1][j+1];

            dp[i][j] = a[i][j]+max(right,max(rightup,rightdown));
        }
    }
    int ans = dp[0][0];
    for(int i=1;i<m;i++) ans = max(ans,dp[i][0]);
    return ans;
}

int maxSumSubmatrix(int a[][MAX],int n,int l){
    if(l>n) return 0;
    int dp[n][n];
    for(int j=0;j<n;j++){
        int sum=0;
        for(int i=0;i<l;i++) sum+=a[i][j];
        dp[0][j] = sum;
        for(int i=1;i<=n-l;i++){
            sum+=(a[i+l-1][j]-a[i-1][j]);
            dp[i][j] = sum;
        }
    }
    int ans = -99999;
    for(int i=0;i<=n-l;i++){
        int sum = 0;
        for(int j=0;j<l;j++) sum+=dp[i][j];
        ans = max(ans,sum);
        for(int j=1;j<=n-l;j++){
            sum+=(dp[i][j+l-1]-dp[i][j-1]);
            ans = max(ans,sum);
        }
    }
    return ans;
}

int main(){
    int a[] = {1, 2, 3, 4};
    //cout<<matrixChainMul(a,4);

    return 0;
}



