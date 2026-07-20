#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<int> visited;

bool dfs(int u) {
    visited[u] = 1; 

    for (int v : adj[u]) {
        if (visited[v] == 0) {
            if (dfs(v)) return true;
        } else if (visited[v] == 1) {
            return true; 
        }
    }

    visited[u] = 2; 
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> V >> E;
        adj.assign(V + 1, vector<int>());
        visited.assign(V + 1, 0);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        bool hasCycle = false;

        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                if (dfs(i)) {
                    hasCycle = true;
                    break;
                }
            }
        }

        cout << (hasCycle ? "YES" : "NO") << endl;
    }
}