#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y) {
    int n=X.size(), m=Y.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i-1]==Y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
    string s1,s2;
    cout<<"Enter two strings: ";
    cin>>s1>>s2;
    cout<<"LCS length = "<<LCS(s1,s2)<<"\n";
}
