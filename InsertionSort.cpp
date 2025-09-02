#include<bits/stdc++.h>
using namespace std;

void insertS(int arr[], int n){
    for(int i=1; i<n; i++) {
        int temp= arr[i];
        int j= i-1;

        while(temp > arr[j] && j>=0) {
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1]= temp;
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

    insertS(arr, n);
    cout <<"\nSorted array in descending: ";
    for(int i=0; i<n; i++) {
        cout <<arr[i]<<" ";
    }
}