#include <bits/stdc++.h>
using namespace std;

int main() {
    int numItems;                       // Number of items or coins
    cin >> numItems;
    vector<int> itemValues(numItems);   // Values of each item/coin
    int totalValue = 0;                 // Total sum of all item values

    for(int i = 0; i < numItems; i++) {
        cin >> itemValues[i];
        totalValue += itemValues[i];
    }

    // Step 1: Sort items in descending order (largest first)
    sort(itemValues.rbegin(), itemValues.rend());

    // Step 2: Initialize variables for greedy selection
    int selectedValueSum = 0;           // Sum of items we select
    int selectedItemCount = 0;          // Count of items we select

    // Step 3: Pick items greedily
    for(int i = 0; i < numItems; i++) {
        selectedValueSum += itemValues[i];
        selectedItemCount++;
        
        // Example condition: stop when our sum > remaining sum
        if(selectedValueSum > totalValue - selectedValueSum) {
            break;
        }
    }

    // Step 4: Output the number of items selected
    cout << selectedItemCount << endl;

    return 0;
}
