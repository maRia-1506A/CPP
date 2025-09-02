#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot= arr[low];
    int i= low+1;
    int j= high;

    while (i<=j) {
        while (arr[i]<=pivot && i<=high) {
            i++;
        }
        while(arr[j] > pivot && j>=low) {
            j--;
        }

        if(i<j) {
            int temp= arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
        }

    }
    int temp= arr[low];
    arr[low]= arr[j];
    arr[j]= temp;

    return j;
}

int quickS(int arr[], int low, int high) {
    if(low<high) {
        int pivotIndex= partition(arr, low, high);
        quickS(arr, low, pivotIndex);
        quickS(arr, pivotIndex+1, high);
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

    quickS(arr, 0, n-1);
    cout <<"\nSorted array by quick: ";
    for(int q: arr) {
        cout <<q<<" ";
    }
    return 0;

}