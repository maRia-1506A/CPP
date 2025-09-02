#include<bits/stdc++.h>
using namespace std;

int linearS(int arr[], int n, int key) {
    for(int i=0; i<n; i++) {
        if(key==arr[i]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout <<"Enter the size of the array: ";
    cin >>n;
    
    int arr[n];
    for(int i=0; i<n; i++) {
        cout <<"A["<<i<<"]: ";
        cin >>arr[i];
    }
    cout <<"You entered: ";
    for(int i=0; i<n; i++) {
        cout <<arr[i]<<" ";
    }

    int key;
    cout <<"\nEnter the value you want to search: ";
    cin >>key;
    
    int result= linearS(arr, n, key);
    if(result==-1) {
        cout <<"Value is not found\n";
    } else {
        cout <<key<<" is found at index "<<result<<" and position "<<result+1<<"\n";
    }


}