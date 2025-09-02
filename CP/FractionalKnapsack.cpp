#include<bits/stdc++.h>
using namespace std;

void fractionalKnapsack(int n, int capacity, vector<int>& weight, vector<int>& value) {
    vector<float> ratio(n);

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Sort items by ratio in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[i]) {
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
            }
        }
    }

    float totalProfit = 0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            // Take the whole item
            currentWeight += weight[i];
            totalProfit += value[i];
        } else {
            // Take fraction of the item
            int remain = capacity - currentWeight;
            totalProfit += ratio[i] * remain;
            break;
        }
    }

    cout << "Maximum profit = " << totalProfit << " tk\n";
}

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weight[i];
        cout << "Value of item " << i + 1 << ": ";
        cin >> value[i];
    }

    fractionalKnapsack(n, capacity, weight, value);

    return 0;
}
