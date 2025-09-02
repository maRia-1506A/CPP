#include<bits/stdc++.h>
using namespace std;

void mergeSort(int low, int high, int arr[]) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Divide
        mergeSort(low, mid, arr);
        mergeSort(mid + 1, high, arr);

        // Conquer (merge two sorted halves)
        int i = low, j = mid + 1, k = 0;
        int temp[high - low + 1];

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
        }
        while (i <= mid) temp[k++] = arr[i++];
        while (j <= high) temp[k++] = arr[j++];

        // Copy back
        for (int p = 0; p < k; p++) {
            arr[low + p] = temp[p];
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    mergeSort(0, n - 1, arr);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
