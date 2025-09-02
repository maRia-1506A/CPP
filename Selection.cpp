#include<bits/stdc++.h>
using namespace std;

void selection(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int min= i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min]) {
                min= j;
            }
        }
        if(min != i) {
            int temp= arr[i];
            arr[i]= arr[min];
            arr[min]= temp;
        }
    }
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
    cout <<"\nOriginal Array: ";
    for(int i=0; i<n; i++) {
        cout <<arr[i]<<" ";
    }

    selection(arr, n);
    cout <<"\nSorted Array: ";
    for(int m: arr) {
        cout <<m<<" ";
    }

    return 0;

}