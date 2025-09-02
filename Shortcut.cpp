#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >>n;

    vector<int> vc(n);
    for(int i=0; i<n; i++) {
        cin >>vc[i];
    }

    //for sorting: sort func
    sort(vc.begin(), vc.end());
    cout <<"Sorted: ";
    for(int i=0; i<n; i++) {
        cout <<vc[i]<<" ";
    }

    string s= "maria";
    sort(s.rbegin(), s.rend());
    cout <<"\n"<<s;

    return 0;
}