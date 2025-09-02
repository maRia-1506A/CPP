#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n + 1, 0);

    cout << "Enter array elements:\n";
    for (int i = 1; i <= n; i++) cin >> arr[i];

    // Build prefix sum
    vector<int> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    cout << "Enter number of queries: ";
    cin >> q;

    cout << "Enter queries (l r) for subarray sum:\n";
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << "Sum(" << l << "," << r << ") = " 
             << prefix[r] - prefix[l - 1] << "\n";
    }
}
