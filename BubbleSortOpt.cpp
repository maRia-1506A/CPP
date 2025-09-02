#include<bits/stdc++.h>
using namespace std;

void bubbleS(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
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

    bubbleS(arr, n);
    cout <<"\nSorted array in ascending: ";
    for(int i=0; i<n; i++) {
        cout <<arr[i]<<" ";
    }
}