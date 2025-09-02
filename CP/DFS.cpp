#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
vector<int> values;

void dfs(int u, int parent, int curGCD) {
    curGCD = __gcd(curGCD, values[u]);
    cout << "Node " << u << " path GCD = " << curGCD << "\n";

    for (int v : tree[u]) {
        if (v != parent) {
            dfs(v, u, curGCD);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    tree.assign(n + 1, {});
    values.assign(n + 1, 0);

    cout << "Enter values for nodes (1 to " << n << "):\n";
    for (int i = 1; i <= n; i++) cin >> values[i];

    cout << "Enter " << n - 1 << " edges:\n";
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << "DFS Traversal with path GCD:\n";
    dfs(1, -1, 0);
}
