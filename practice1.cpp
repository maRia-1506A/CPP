#include<bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >>x1 >>y1 >>x2 >>y2;
    
    if(x2==x1 && y2==y1) {
        cout <<"Equal";
    } else if(x2>= x1 && y2<=y1) {
        cout <<"Inside";
    } else {
        cout <<"Nothing";
    }
    return 0;
}