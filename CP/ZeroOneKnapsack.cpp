#include<bits/stdc++.h>
using namespace std;

int max(int x, int y) {
    return (x>y) ? x:y;
}

int knapsack(int n, int capacity, vector<int>& profit, vector<int>& weight) {
    vector<vector<int>> k(n+1, vector<int>(capacity+1, 0)); //2d vector: n+1= row numb, cap..+1=col numb, 0= start value
    //2d table:   k[i][w] → Maximum profit for weight w considering items up to the i-th item.

    for(int i=0; i<=n; i++) {
        for(int w=0; w<=capacity; w++) {
            if(i==0 || w==0) {
                k[i][w]= 0;
            } else if(weight[i]<=w) { //if the item fit
                k[i][w]= max(
                    k[i-1][w], //item not taken
                    profit[i]+k[i-1][w-weight[i]] //item taken(prf incrs, wgt decrs)
                );
            } else {
                k[i][w]= k[i-1][w];
            }
        }
    }
    return k[n][capacity];
}

int main() {
    int n, capacity;

    cout <<"Enter the number of items: ";
    cin >>n;
    cout <<"Enter knapsack capacity: ";
    cin >>capacity;

    vector<int> profit(n+1), weight(n+1); //1d vector(starts from 1)
 
    for(int i=1; i<=n; i++) {
        cout <<"Profit of item "<<i<<": ";
        cin >>profit[i];
        cout <<"Weight of item "<<i<<": ";
        cin >>weight[i];
    }

    int maxProfit= knapsack(n, capacity, profit, weight);
    cout <<"Maximum profit: "<<maxProfit<<"\n";
    return 0;
}