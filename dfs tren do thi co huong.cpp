#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
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
        int V, E, u;
        cin >> V >> E >> u;
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < E; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y); 
        }
        for (int i = 1; i <= V; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        dfs(u);
        cout << endl;
    }
}