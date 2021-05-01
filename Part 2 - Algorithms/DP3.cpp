#include <iostream>
using namespace std;

/*DP: String-related problems
LCS, LCSubstr, LPS, LPSubstr,editDistance*/

int LCS(string str1,string str2,int n1,int n2){
    int dp[n1+1][n2+1];

    for(int i=0;i<=n1;i++) dp[i][0] = 0;
    for(int i=0;i<=n2;i++) dp[0][i] = 0;

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n1][n2];
}

int LCSubstr(string str1,string str2,int n1,int n2){
    int dp[n1+1][n2+1];
    int ans = 0;

    for(int i=0;i<=n1;i++) dp[i][0] = 0;
    for(int i=0;i<=n2;i++) dp[0][i] = 0;

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}

int LPS(string str,int n){
    int dp[n][n];
    for(int i=0;i<n;i++) dp[i][i] = 1;
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            if(l==2 && str[i]==str[j]) dp[i][j] = 2;
            else if(str[i]==str[j]) dp[i][j] = dp[i+1][j-1]+2;
            else dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }
    }
    return dp[0][n-1];
}

int LPSubstr(string str,int n){
    bool dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) dp[i][j] = false;
    }
    for(int i=0;i<n;i++) dp[i][i] = true;

    int ans = 1;
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            dp[i][i+1] = true;
            ans = 2;
        }
    }
    for(int l=3;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = i+l-1;
            if(dp[i+1][j-1] && str[i]==str[j]){
                dp[i][j] = true;
                ans = max(ans,l);
            }
        }
    }
    return ans;
}

int editDistance(string str1,string str2,int n1,int n2){
    int dp[n1+1][n2+1];

    for(int i=0;i<=n1;i++) dp[i][0] = i;
    for(int i=0;i<=n2;i++) dp[0][i] = i;

    for(int i=1;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1+min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
        }
    }

    return dp[n1][n2];
}

int main(){
    string str = "GEEKS FOR GEEKS";
    string str1 = "OldSite:GeeksforGeeks.org";
    string str2 = "NewSite:GeeksQuiz.com";

    //string str = "forgeeksskeegfor";
    //string str1 = "sunday";
    //string str2 = "saturday";

    int n = str.length();
    int n1 = str1.length();
    int n2 = str2.length();

   // cout<<editDistance(str1,str2,n1,n2)<<endl;
    cout<<LPS(str,n)<<endl;
    return 0;
}
