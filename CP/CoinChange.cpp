#include <bits/stdc++.h>
using namespace std;

// Minimum coins to make sum
int minCoins(vector<int>& coins, int amount) {
    const int INF=1e9;
    vector<int> dp(amount+1, INF); //vector<Type> name(size, initial_value)
    dp[0]=0;
    for(int coin: coins){
        for(int i=coin;i<=amount;i++){
            dp[i]=min(dp[i], dp[i-coin]+1);
        }
    }
    return dp[amount]==INF ? -1: dp[amount];
}

// Number of ways to make sum
int countWays(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int coin: coins){
        for(int i=coin;i<=amount;i++){
            dp[i]+=dp[i-coin];
        }
    }
    return dp[amount];
}

int main(){
    int n,amount;
    cout<<"Enter number of coins and target: ";
    cin>>n>>amount;
    vector<int> coins(n);
    cout<<"Enter coins:\n";
    for(int i=0;i<n;i++) cin>>coins[i];

    cout<<"Min coins = "<<minCoins(coins,amount)<<"\n";
    cout<<"Ways = "<<countWays(coins,amount)<<"\n";
}
