#include<bits/stdc++.h>
using namespace std;

#define MAX_GROUPS 100
#define MAX_BUSES 100
#define BUS_CAPACITY 7

int main() {
    int n;
    cout <<"Enter the number of groups: ";
    cin >>n;

    int groupsize[MAX_GROUPS];
    cout <<"Enter the size of each group: ";
    for(int i=0; i<n; i++) {
        cin >>groupsize[i];
    }

    int bus_seat[MAX_BUSES]= {0};
    int busCount= 0;

    for(int i=0; i<n; i++) {
        int placed= 0; //grp is not seated
        for(int j=0; j<busCount; j++) {
            if(bus_seat[j]+groupsize[i] <= BUS_CAPACITY) {
                bus_seat[j] += groupsize[i]; //numb i people will seat in bus j
                placed =1; //grp is seated
                break;
            }
        }

        if(!placed) {
            bus_seat[busCount]= groupsize[i];
            busCount++;
        }
    }

    cout <<"Minimum number of mini bus: "<<busCount<<"\n";
    return 0;
}