#include<bits/stdc++.h>
using namespace std;

int main() {  
    int n;
    cin >>n;

    vector<int> sales(n);
    for(int i=0; i<n; i++) {
        cin >>sales[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(sales[j]>sales[j+1]) {
                swap(sales[j], sales[j+1]);
            }
        }
    }

    for(int s: sales) {
        cout <<s<<" "<<"\n";
    }
    return 0;
}

