#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }

        cout << count << endl;
    }
}