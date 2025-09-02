#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i; // index found
    }
    return -1;
}

int binary_search_custom(int arr[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    cout << "Linear Search: ";
    int idx1 = linear_search(arr, n, key);
    if (idx1 != -1) cout << "Found at index " << idx1 << "\n";
    else cout << "Not found\n";

    sort(arr, arr + n); // must sort before binary search
    cout << "Binary Search (sorted array): ";
    int idx2 = binary_search_custom(arr, n, key);
    if (idx2 != -1) cout << "Found at index " << idx2 << "\n";
    else cout << "Not found\n";
}
